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
uint8_t slaveOne[1] = {0x01};
uint8_t slaveTwo[1] = {0x01};
uint8_t sendData_[1] = {0x03};

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
    sendData_[0] = 0x04;
}

void sendData(struct spi_ioc_transfer transfer)
{
    // Perform bitwise OR operation with sendData
    ((uint8_t *)transfer.tx_buf)[0] |= sendData_[0];

    // Print the data before sending (for testing purposes)
    printf("Sending data: %x\n", ((uint8_t *)transfer.tx_buf)[0]);

    ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer);

    // Print received data (for testing purposes)
    printf("Received data: %x\n", ((uint8_t *)transfer.rx_buf)[0]);
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

    // Handle received data
    printf("Received data from transfer1: %x\n", ((uint8_t *)transfer1.rx_buf)[0]);
    printf("Received data from transfer2: %x\n", ((uint8_t *)transfer2.rx_buf)[0]);

    cleanup();
    close(spi_fd);
    return 0;
}
