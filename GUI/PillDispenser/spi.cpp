#include "spi.h"

// Default settings for spi device
const char* SPI::device = "/dev/spidev0.1";
uint8_t SPI::bits = 8;
uint32_t SPI::speed = 10000000;
uint16_t SPI::delay = 0;
uint32_t SPI::mode = SPI_MODE_3;

SPI::SPI() {
    fd = open(device, O_RDWR);

    // Needs error handling badly!!
    ioctl(fd, SPI_IOC_WR_MODE, &mode);
    ioctl(fd, SPI_IOC_RD_MODE, &mode);

    ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);

    ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
}

SPI::~SPI() { close(fd); }

void SPI::transfer(unsigned int* command, unsigned int size) {
    struct spi_ioc_transfer tr[size];

    // Setup the transmit buffer;
    //uint8_t tx[size];

    for (size_t i = 0; i < size; i++) {
        tr[i].tx_buf = reinterpret_cast<unsigned long>(&command[i]);
        tr[i].rx_buf = 0;
        tr[i].len = sizeof(command[i]);
        tr[i].delay_usecs = delay;
        tr[i].speed_hz = speed;
        tr[i].bits_per_word = bits;
        tr[i].cs_change = 0;
    }

    // Needs error handling
    ioctl(fd, SPI_IOC_MESSAGE(size), &tr);
}

void SPI::recieve(unsigned int* command, unsigned int size) {
    struct spi_ioc_transfer re[size];

    // Setup the transmit buffer;
    //uint8_t rx[size];

    for (size_t i = 0; i < size; i++) {
        re[i].tx_buf = 0;
        re[i].rx_buf = reinterpret_cast<unsigned long>(&command[i]);
        re[i].len = sizeof(command[i]);
        re[i].delay_usecs = delay;
        re[i].speed_hz = speed;
        re[i].bits_per_word = bits;
        re[i].cs_change = 0;
    }

    // Needs error handling
    ioctl(fd, SPI_IOC_MESSAGE(size), &re);
}
