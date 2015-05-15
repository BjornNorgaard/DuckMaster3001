#include "Protokol.h"

// Default settings for spi device
const char* Protokol::device = "/dev/spidev0.1";
uint8_t Protokol::bits = 8;
uint32_t Protokol::speed = 10000000;
uint16_t Protokol::delay = 0;
uint32_t Protokol::mode = SPI_MODE_3;

Protokol::Protokol() {
    fd = open(device, O_RDWR);

    // Needs error handling badly!!
    ioctl(fd, SPI_IOC_WR_MODE, &mode);
    ioctl(fd, SPI_IOC_RD_MODE, &mode);

    ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);

    ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
}

Protokol::~Protokol() { close(fd); }

uint8_t Protokol::checksum(uint8_t value) {
    // Checksum implementation
    return 0;
}

void Protokol::transfer(uint8_t* command, uint8_t size) {
    uint8_t msgSize = size + 2;
    struct spi_ioc_transfer tr[msgSize];

    // Setup the transmit buffer;
    uint8_t tx[msgSize];
    // First the amount of bytes transferred
    tx[0] = msgSize;
    // Then the command
    for (size_t i = 1; i < size + 1; i++) tx[i] = command[i - 1];
    // Lastly the checksum
    tx[size + 1] = checksum(1);

    for (size_t i = 0; i < msgSize; i++) {
        tr[i].tx_buf = reinterpret_cast<unsigned long>(&tx[i]);
        tr[i].rx_buf = 0;
        tr[i].len = sizeof(tx[i]);
        tr[i].delay_usecs = delay;
        tr[i].speed_hz = speed;
        tr[i].bits_per_word = bits;
        tr[i].cs_change = 0;
    }

    // Needs error handling
    ioctl(fd, SPI_IOC_MESSAGE(msgSize), &tr);
}

bool Protokol::dispensePill(uint8_t id, uint8_t amount) {
    uint8_t size = 3;
    uint8_t command[size];

    command[0] = 0x01;
    command[1] = id;
    command[2] = amount;

    transfer(command, size);

    // Needs error handling

    return true;
}
