#include <linux/gpio.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of_gpio.h>

const int first_minor = 0;
const int max_devices = 255;
static dev_t devno;
static struct cdev led3_cdev;
struct file_operations led3_fops;
static struct device *mygpio_device;

static struct class *led3_class;

struct gpio_dev {
    int gpio;
    int flag;
};

static struct gpio_dev gpio_devs[255];
int gpios_len;

static int plat_drv_probe(struct platform_device *pdev)
{
    printk ("Hello form probe");
    int err;
    enum of_gpio_flags flag;
    

    if ((gpios_len = of_gpio_count(pdev->dev.of_node))<0) {
        dev_err(&pdev->dev, "Failed to read of_gpio_count\n");
        return -EINVAL;
    }

    for (int i = 0; i < gpios_len; i++) {
        gpio_devs[i].gpio = of_get_gpio_flags(pdev->dev.of_node, i, &flag);
        if (gpio_devs[i].gpio < 0) {
            pr_err("Failed to get GPIO number\n");
            return gpio_devs[i].gpio;
        }

        gpio_devs[i].flag = (int)flag;

        err = gpio_request(gpio_devs[i].gpio, "led gpio");

        if (err < 0) {
            pr_err("Failed to get GPIO flags\n");
            return err;
        }
        if (gpio_devs[i].flag == 0) {
            pr_info("saetter gpio %d som input\n", gpio_devs[i].gpio);
            gpio_direction_input(gpio_devs[i].gpio);
        } else {
            pr_info("saetter gpio %d som output\n", gpio_devs[i].gpio);
            gpio_direction_output(gpio_devs[i].gpio, 0);
        }

        if (err < 0) {
            pr_err("Failed to set GPIO direction\n");
            gpio_free(gpio_devs[i].gpio);
            return err;
        }

        mygpio_device = device_create(led3_class, NULL, 
        MKDEV(MAJOR(devno), i), NULL, "mygpio%d", gpio_devs[i].gpio);
        if (IS_ERR(mygpio_device)) {
            dev_err(&pdev->dev, "Failed to create device: %d\n", i);
            err = PTR_ERR(mygpio_device);
            gpio_free(gpio_devs[i].gpio);
            return err;
        }
        
    }
    return 0;
}


// modificeres i opgave a del2 exercise 6
static int my_plat_drv_remove(struct platform_device *pdev)
{
    int i;

    printk("Hello from remove\n");

    for (i = 0; i < gpios_len; i++) {
        // Destroy device
        device_destroy(led3_class, MKDEV(MAJOR(devno), i));
        // Free GPIO
        gpio_free(gpio_devs[i].gpio);
    }
    
    return 0;
}

//tilføjelse opgave b exercise 6
static const struct of_device_id my_led_platform_device_match[] = {
    { .compatible = "ase, plat_drv", },
    {},
};
//tilføjelse opgave b exercise 6
static struct platform_driver my_led_platform_driver = {
    .probe = plat_drv_probe,
    .remove = my_plat_drv_remove,
    .driver = {
    .name = "plat_drv_NEW",
    .of_match_table = my_led_platform_device_match,
    .owner = THIS_MODULE,
    },
};


int my_plat_drv_open(struct inode *inode, struct file *filep)
{
    int major, minor;
    major = MAJOR(inode->i_rdev);
    minor = MINOR(inode->i_rdev);
    printk("Opening my_plat_drv Device [major], [minor]: %i, %i\n", major, minor);
    return 0;
}

 int my_plat_drv_release(struct inode *inode, struct file *filep)
{
    int minor, major;

    major = MAJOR(inode->i_rdev);
    minor = MINOR(inode->i_rdev);
    printk("Closing/Releasing my_plat_drv Device [major], [minor]: %i, %i\n", major, minor);

    return 0;
}

ssize_t my_plat_drv_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos)
{
    //tilføjes i opgave b del2 exercise 6
    int minor = iminor(filep->f_inode);

    if (minor >= gpios_len) {
        pr_err("Invalid minor number\n");
        return -EINVAL;
    }

    char status[64]; // Buffer til at gemme statusinformationen
    int led_status;

    //modificeres i opgave b del2 exercise 6
    // læser statusen for den bestemte GPIO/led
    led_status = gpio_get_value(gpio_devs[minor].gpio);


    // Konverter statusen til en streng
    if(gpio_devs[minor].flag==0)
    {
    snprintf(status, sizeof(status), "knappen med gpio.no %d er %s \n",
     gpio_devs[minor].gpio, led_status ? "ikke trykket" : "trykket");
    }
    else
    {
    snprintf(status, sizeof(status), "led med gpio.no %d er %s \n", 
    gpio_devs[minor].gpio, led_status ? "tændt" : "slukket");
    }
    // Beregn længden af den data, der skal kopieres til brugerområdet
    size_t len = strlen(status);

    // Kopier statusstrengen fra kernelområdet til brugerområdet
    ssize_t retval = copy_to_user(buf, status, len);

    if (retval == 0) {
        // Læsningen var vellykket
        *f_pos += len;
        return len;
    } else {
        // Der opstod en fejl ved kopiering til brugerområdet
        return -EFAULT;
    } 
 }

 ssize_t my_plat_drv_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos)
{
    //tilføjes i opgave b del2 exercise 6
    int minor = iminor(filep->f_inode);
    pr_info("in write\n");
    if (minor >= gpios_len) {
        pr_err("Invalid minor number\n");
        return -EINVAL;
    }

    char buf[32]; // Buffer til at gemme dataen fra brugerområdet
    int led_state=1;

    
    // Læs data fra brugerområdet til kernel bufferen
    if (copy_from_user(buf, ubuf, min(count, sizeof(buf))) != 0) {
        return -EFAULT; // Der opstod en fejl ved kopiering
    }

    //modificeres i opgave b del2 exercise 6
    // Konverter dataen til en intern repræsentation
    if (sscanf(buf, "%d", &led_state) != 1) {
        pr_err("Error in message\n");
        return -EINVAL; // Ugyldig data blev modtaget
    }

    pr_info("writing %d to %d\n", led_state, gpio_devs[minor].gpio);
    // Styr LEDer baseret på den konverterede værdi
    gpio_set_value(gpio_devs[minor].gpio, led_state);
   
    return count; // Returnér antallet af bytes, der blev skrevet
}

 struct file_operations led3_fops = {
    .owner = THIS_MODULE,
    .open = my_plat_drv_open,
    .release = my_plat_drv_release,
    .read = my_plat_drv_read,
    .write = my_plat_drv_write
};




 static int my_plat_drv_init(void)
{
    int err = 0;

    err = alloc_chrdev_region(&devno, first_minor, max_devices, "led3-driver");
    if (MAJOR(devno) <= 0) {
        pr_err("Failed to register chardev\n");
        return err;
    }

    pr_info("led3-driver got Major %i\n", MAJOR(devno));

    led3_class = class_create(THIS_MODULE, "led3-class");
    if (IS_ERR(led3_class))
        pr_err("Failed to create class");

    cdev_init(&led3_cdev, &led3_fops);

    err = cdev_add(&led3_cdev, devno, max_devices);
    if (err) {
        pr_err("Failed to add cdev\n");
        return err;
    }

    platform_driver_register(&my_led_platform_driver);

    return err;
}
// modificeres i opgave a del2 exercise 6
static void my_plat_drv_exit(void)
{
    platform_driver_unregister(&my_led_platform_driver);

    cdev_del(&led3_cdev);

    class_destroy(led3_class);

    unregister_chrdev_region(devno, max_devices);

}

module_init(my_plat_drv_init);
module_exit(my_plat_drv_exit);

MODULE_AUTHOR("Jesper Myllerup");
MODULE_LICENSE("GPL");