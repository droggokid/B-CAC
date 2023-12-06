#include <linux/cdev.h>    // cdev_add, cdev_init
#include <linux/uaccess.h> // copy_to_user
#include <linux/module.h>  // module_init, GPL
#include <linux/spi/spi.h> // spi_sync,

#define MAXLEN 32
#define MODULE_DEBUG 1 // Enable/Disable Debug messages
#define BYTES_TO_RECEIVE 3

/* Char Driver Globals */
static struct spi_driver spi_drv_spi_driver;
struct file_operations spi_drv_fops;
static struct class *spi_drv_class;
static dev_t devno;
static struct cdev spi_drv_cdev;
uint8_t command_byte = 0x00;
static uint32_t minutter_ = 0;
static uint32_t sekunder_ = 0;
static uint32_t millisekunder_ = 0;
static bool dataProcessed = false;

/* Definition of SPI devices */
struct psoc_spi_dev
{
    struct spi_device *spi; // Pointer to SPI device
    int channel;            // channel, ex. adc ch 0
};

/* Array of SPI devices */
/* Minor used to index array */
struct psoc_spi_dev spi_devs[2];
const int spi_devs_len = 2;  // Max nbr of devices
static int spi_devs_cnt = 0; // Nbr devices present

/* Macro to handle Errors */
#define ERRGOTO(label, ...)  \
    {                        \
        printk(__VA_ARGS__); \
        goto label;          \
    }                        \
    while (0)

/**********************************************************
 * CHARACTER DRIVER METHODS
 **********************************************************/

static int __init spi_drv_init(void)
{
    int err = 0;

    printk("spi_drv driver initializing\n");

    /* Allocate major number range for spi_devs_len devices */
    err = alloc_chrdev_region(&devno, 0, spi_devs_len, "spi_drv");
    if (err < 0)
        ERRGOTO(err_no_cleanup, "Failed to register chardev\n");
    printk(KERN_ALERT "Assigned major no: %i\n", MAJOR(devno));

    cdev_init(&spi_drv_cdev, &spi_drv_fops);
    err = cdev_add(&spi_drv_cdev, devno, spi_devs_len);
    if (err)
        ERRGOTO(err_cleanup_chrdev, "Failed to create class");

    /* Populate sysfs entries */
    spi_drv_class = class_create(THIS_MODULE, "spi_drv_class");
    if (IS_ERR(spi_drv_class))
        ERRGOTO(err_cleanup_cdev, "Failed to create class");

    /* Register SPI Driver */
    /* THIS WILL INVOKE PROBE, IF DEVICE IS PRESENT!!! */
    err = spi_register_driver(&spi_drv_spi_driver);
    if (err)
        ERRGOTO(err_cleanup_class, "Failed SPI Registration\n");

    /* Success */
    return 0;

    /* Errors during Initialization */
err_cleanup_class:
    class_destroy(spi_drv_class);

err_cleanup_cdev:
    cdev_del(&spi_drv_cdev);

err_cleanup_chrdev:
    unregister_chrdev_region(devno, spi_devs_len);

err_no_cleanup:
    return err;
}

/*
 * Character Driver Module Exit Method
 */
static void __exit spi_drv_exit(void)
{
    printk("spi_drv driver Exit\n");

    spi_unregister_driver(&spi_drv_spi_driver);
    class_destroy(spi_drv_class);
    cdev_del(&spi_drv_cdev);
    unregister_chrdev_region(devno, 255);
}

/*
 * Character Driver Write File Operations Method
 */
ssize_t spi_drv_write(struct file *filep, const char __user *ubuf,
                      size_t count, loff_t *f_pos)
{
    int minor, len, value;
    char kbuf[MAXLEN];

    minor = iminor(filep->f_inode);

    printk(KERN_ALERT "Writing to spi_drv [Minor] %i \n", minor);

    /* Limit copy length to MAXLEN allocated and copy from user */
    len = count < MAXLEN ? count : MAXLEN;
    if (copy_from_user(kbuf, ubuf, len))
        return -EFAULT;

    /* Pad null termination to string */
    kbuf[len] = '\0';

    if (MODULE_DEBUG)
        printk("string from user: %s\n", kbuf);

    /* Convert string to int */
    if (sscanf(kbuf, "%i", &value) != 1)
    {
        printk(KERN_ALERT "Failed to convert string to integer\n");
        return -EINVAL; // Return an appropriate error code
    }

    command_byte = value;

    /* Initialize SPI message and transfers */
    struct spi_transfer t[1];
    struct spi_message m;
    uint8_t tx_buf = command_byte;

    memset(t, 0, sizeof(t));
    spi_message_init(&m);
    m.spi = spi_devs[minor].spi;

    /* Set up the SPI transfer for sending the command to the PSoC */
    t[0].tx_buf = &tx_buf;
    t[0].len = 1;
    t[0].bits_per_word = 8;
    spi_message_add_tail(&t[0], &m);

    /* Send the command byte */
    int err = spi_sync(spi_devs[minor].spi, &m);
    if (err)
    {
        printk(KERN_ALERT "FAILED spi_sync: %d\n", err);
        // Handle the error as needed
        return err;
    }

    /* Legacy file ptr f_pos. Used to support
     * random access but in char drv we don't!
     * Move it the length actually written
     * for compatibility */
    *f_pos += len;

    /* return length actually written */
    return len;
}

/*
 * Character Driver Read File Operations Method
 */
ssize_t spi_drv_read(struct file *filep, char __user *ubuf,
                     size_t count, loff_t *f_pos)
{
    int minor, len;
    struct spi_transfer t[1];
    struct spi_message m;
    char resultBuf[MAXLEN];
    uint8_t rx_buf_time[BYTES_TO_RECEIVE];
    uint8_t resultBuff[2];
    uint8_t tx_byte = 0x01;

    s16 result;

    minor = iminor(filep->f_inode);

    /* Initialize SPI message and transfers */
    memset(t, 0, sizeof(t));
    spi_message_init(&m);
    m.spi = spi_devs[minor].spi;

        t[0].tx_buf = &tx_byte;
        t[0].rx_buf = &resultBuff[minor]; // Use minor to index the result buffer based on the current slave
        t[0].len = 1;
        t[0].bits_per_word = 8; // Specify bits_per_word
        t[0].delay_usecs = 1000;
        spi_message_add_tail(&t[0], &m);

        int err = spi_sync(spi_devs[minor].spi, &m);

        if (err)
        {
            printk(KERN_ALERT "FAILED spi_sync: %d\n", err);
            return err;
        }

        result = resultBuff[minor];

        if (MODULE_DEBUG)
            printk(KERN_ALERT "%s-%i read: %i\n",
                   spi_devs[minor].spi->modalias, spi_devs[minor].channel, result);

        /* Convert integer to string limited to "count" size. Returns
         * length excluding NULL termination */
        len = snprintf(resultBuf, count, "%u\n", result);
        if (len >= count)
        {
            printk(KERN_ALERT "User buffer too small to hold the result\n");
            return -EINVAL; // Return an appropriate error code
        }

        /* Append Length of NULL termination */
        len++;

        /* Copy data to user space */
        if (copy_to_user(ubuf, resultBuf, len))
            return -EFAULT;

        /* Move fileptr */
        *f_pos += len;

    return len;
}


  
    

/*
 * Character Driver File Operations Structure
 */
struct file_operations spi_drv_fops =
    {
        .owner = THIS_MODULE,
        .write = spi_drv_write,
        .read = spi_drv_read,
};

/**********************************************************
 * LINUX DEVICE MODEL METHODS (spi)
 **********************************************************/

/*
 * spi_drv Probe
 * Called when a device with the name "spi_drv" is
 * registered.
 */
static int spi_drv_probe(struct spi_device *sdev)
{
    int err = 0;
    struct device *spi_drv_device;

    printk(KERN_DEBUG "New SPI device: %s using chip select: %i\n",
           sdev->modalias, sdev->chip_select);

    /* Check we are not creating more
       devices than we have space for */
    if (spi_devs_cnt >= spi_devs_len)
    {
        printk(KERN_ERR "Too many SPI devices for driver\n");
        return -ENODEV;
    }

    /* Configure bits_per_word, always 8-bit for RPI!!! */

    sdev->bits_per_word = 8;
    spi_setup(sdev);

    /* Create devices, populate sysfs and
       active udev to create devices in /dev */

    spi_drv_device = device_create(spi_drv_class, NULL,
                                   MKDEV(MAJOR(devno), spi_devs_cnt),
                                   NULL, "spi_drv%d", spi_devs_cnt);
    if (IS_ERR(spi_drv_device))
    {
        printk(KERN_ALERT "FAILED TO CREATE DEVICE\n");
        return PTR_ERR(spi_drv_device);
    }

    /* Update local array of SPI devices */
    spi_devs[spi_devs_cnt].spi = sdev;
    spi_devs[spi_devs_cnt].channel = sdev->chip_select; // channel address
    ++spi_devs_cnt;

    return err;
}

static int spi_drv_remove(struct spi_device *sdev)
{
    int its_minor = 0;

    printk(KERN_ALERT "Removing spi device\n");

    /* Find and destroy devices created in probe() */
    for (int i = 0; i < spi_devs_len; i++)
    {
        if (spi_devs[i].spi == sdev)
        {
            device_destroy(spi_drv_class, MKDEV(MAJOR(devno), its_minor));
            break;
        }
        ++its_minor;
    }

    return 0;
}

/*
 * spi Driver Struct
 * Holds function pointers to probe/release
 * methods and the name under which it is registered
 */
static const struct of_device_id of_spi_drv_spi_device_match[] = {
    {
        .compatible = "ase, spi_drv",
    },
    {},
};

static struct spi_driver spi_drv_spi_driver = {
    .probe = spi_drv_probe,
    .remove = spi_drv_remove,
    .driver = {
        .name = "spi_drv",
        .bus = &spi_bus_type,
        .of_match_table = of_spi_drv_spi_device_match,
        .owner = THIS_MODULE,
    },
};

/**********************************************************
 * GENERIC LINUX DEVICE DRIVER STUFF
 **********************************************************/

/*
 * Assignment of module init/exit methods
 */
module_init(spi_drv_init);
module_exit(spi_drv_exit);

/*
 * Assignment of author and license
 */
MODULE_AUTHOR("Peter Hoegh Mikkelsen <phm@ase.au.dk>");
MODULE_LICENSE("GPL");
