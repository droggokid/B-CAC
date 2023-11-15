#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <string.h>

#define SPI_MODE 0
#define SPI_BITS_PER_WORD 8
#define SPI_SPEED 1000000

int spi_fd;
uint8_t slaveOne[8] = {1, 0, 0, 0, 0, 0, 0, 0};
uint8_t slaveTwo[8] = {0, 1, 0, 0, 0, 0, 0, 0};
uint8_t sendData_[8] = {0, 0, 0, 0, 0, 0, 0, 0};

struct spi_ioc_transfer transfer1 = {
    .tx_buf = 0,
    .rx_buf = 0,
    .len = sizeof(sendData_),
    .speed_hz = SPI_SPEED,
    .bits_per_word = SPI_BITS_PER_WORD,
};

struct spi_ioc_transfer transfer2 = {
    .tx_buf = 0,
    .rx_buf = 0,
    .len = sizeof(slaveTwo),
    .speed_hz = SPI_SPEED,
    .bits_per_word = SPI_BITS_PER_WORD,
};

int spi_init(char *device)
{
    int ret;
    spi_fd = open(device, O_RDWR);
    if (spi_fd < 0)
    {
        perror("can't open device");
        return -1;
    }

    uint8_t mode = SPI_MODE;
    ret = ioctl(spi_fd, SPI_IOC_WR_MODE, &mode);
    if (ret == -1)
    {
        perror("Can't set spi mode");
        return -1;
    }

    uint8_t bits_per_word = SPI_BITS_PER_WORD;
    ret = ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bits_per_word);
    if (ret == -1)
    {
        perror("Can't set bits per word");
        return -1;
    }

    uint32_t speed = SPI_SPEED;
    ret = ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1)
    {
        perror("can't set max speed hz");
        return -1;
    }

    // Dynamically allocate memory for buffers
    transfer1.tx_buf = (unsigned long)malloc(sizeof(sendData_));
    transfer1.rx_buf = (unsigned long)malloc(sizeof(sendData_));

    transfer2.tx_buf = (unsigned long)malloc(sizeof(slaveTwo));
    transfer2.rx_buf = (unsigned long)malloc(sizeof(slaveTwo));

    return 0;
}

void cleanup()
{
    // Free allocated memory
    free((void *)transfer1.tx_buf);
    free((void *)transfer1.rx_buf);

    free((void *)transfer2.tx_buf);
    free((void *)transfer2.rx_buf);
}

void updateDataFromUI()
{
    // Simulate updating data from UI
    // You can replace this with actual UI data update logic
    // For testing, let's set some values in sendData_
    sendData_[0] = 0xAA;
    sendData_[1] = 0xBB;
    sendData_[2] = 0xCC;
}

void sendData(struct spi_ioc_transfer transfer)
{
    // Print the data before sending (for testing purposes)
    printf("Sending data:\n");
    for (int i = 0; i < transfer.len; ++i)
    {
        printf("0x%02X ", ((uint8_t *)transfer.tx_buf)[i]);
    }
    printf("\n");

    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer);

    // Print received data (for testing purposes)
    printf("Received data:\n");
    for (int i = 0; i < transfer.len; ++i)
    {
        printf("0x%02X ", ((uint8_t *)transfer.rx_buf)[i]);
    }
    printf("\n");
}

int main()
{
    char *device = "/dev/spidev0.0";
    if (spi_init(device) < 0)
    {
        printf("Failed to initialize SPI\n");
        return -1;
    }

    updateDataFromUI();

    // Copy data to the dynamically allocated buffers
    memcpy((void *)transfer1.tx_buf, sendData_, sizeof(sendData_));
    memcpy((void *)transfer1.rx_buf, sendData_, sizeof(sendData_));

    memcpy((void *)transfer2.tx_buf, slaveTwo, sizeof(slaveTwo));
    memcpy((void *)transfer2.rx_buf, slaveTwo, sizeof(slaveTwo));

    sendData(transfer1);
    sendData(transfer2);

    cleanup();
    close(spi_fd);
    return 0;
}
