#include "SPIInterface.h"

// Default settings for spi device
const char* SPIInterface::device = "/dev/spidev0.1";
uint8_t SPIInterface::bits = 8;
uint32_t SPIInterface::speed = 50000;
uint16_t SPIInterface::delay = 50;
uint32_t SPIInterface::mode = SPI_MODE_3;

SPIInterface::SPIInterface() {
    fd = open(device, O_RDWR);

    // Needs error handling badly!!

    ioctl(fd, SPI_IOC_WR_MODE, &mode);

    ioctl(fd, SPI_IOC_RD_MODE, &mode);

    ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);

    ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);

    ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

    ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
}

SPIInterface::~SPIInterface() {
    close(fd);
}

uint8_t SPIInterface::checksum(uint8_t value) {
    // Checksum implementation
    return 0;
}

void SPIInterface::transfer(uint8_t* command, uint8_t size) {
    uint8_t tx[size + 2];    

    // Setup the transmit buffer;
    // First the amount of bytes transferred
    tx[0] = size + 2;
    // Then the command
    for (size_t i = 1; i < size; i++)
        tx[i] = *(command + i);
    // Lastly the checksum
    tx[size+1] = checksum(1);

    struct spi_ioc_transfer tr;
    tr.tx_buf = (unsigned long)tx;
    tr.rx_buf = 0;
    tr.len = tx[0];
    tr.delay_usecs = delay;
    tr.speed_hz = speed;
    tr.bits_per_word = bits;

    // Needs error handling 
    ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
}

bool SPIInterface::dispensePill(uint8_t id, uint8_t amount) {
    uint8_t size;
    uint8_t command[3];

    command[0] = 0x01;
    command[1] = id;
    command[2] = amount;

    transfer(command, size);

    // Needs error handling

    return true;
}
