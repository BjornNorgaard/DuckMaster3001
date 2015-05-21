#include "spi.h"

SPI::SPI() {
    this->device = "/dev/spidev0.1";
    this->bits = 8;
    this->speed = 10000000;
    this->delay = 0;
    this->mode = SPI_MODE_3;

    openSPI();
}

SPI::~SPI() {
    closeSPI();
}

void SPI::openSPI() {
    this->fd = open(device, O_RDWR);
    if (fd < 0)
        std::cout << "Can't open SPI device.";

    if (ioctl(fd, SPI_IOC_WR_MODE, &mode) == -1)
        std::cout << "Can't set SPI mode.";
    if (ioctl(fd, SPI_IOC_RD_MODE, &mode) == -1)
        std::cout << "Can't set SPI mode.";

    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits) == -1)
        std::cout << "Can't set bits per word.";
    if (ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits) == -1)
        std::cout << "Can't set bits per word.";

    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) == -1)
        std::cout << "Can't set max speed.";
    if (ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed) == -1)
        std::cout << "Can't set max speed.";
}

void SPI::closeSPI() {
    if (close(fd) < 0)
        std::cout << "Can't close SPI device.";
}

int SPI::transfer(unsigned char command[], size_t size) {
    int ret;

    struct spi_ioc_transfer tr;
    tr.tx_buf = reinterpret_cast<unsigned long>(command);
    tr.rx_buf = 0;
    tr.len = size;
    tr.delay_usecs = delay;
    tr.speed_hz = speed;
    tr.bits_per_word = bits;
    tr.cs_change = 0;

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 0)
        std::cout << "Can't send message";

    return ret;
}

void SPI::recieve(unsigned char command[], size_t size) {
    int ret;

    struct spi_ioc_transfer tr;
    tr.tx_buf = 0;
    tr.rx_buf = reinterpret_cast<unsigned long>(command);
    tr.len = size;
    tr.delay_usecs = delay;
    tr.speed_hz = speed;
    tr.bits_per_word = bits;
    tr.cs_change = 0;

    ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 0)
        std::cout << "Can't send message";
}
