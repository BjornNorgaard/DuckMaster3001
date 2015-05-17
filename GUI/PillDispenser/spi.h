#ifndef SPI_H
#define SPI_H

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

class SPI {
  public:
    SPI();
    ~SPI();
    void transfer(unsigned int* command, unsigned int size);
    void recieve(unsigned int* command, unsigned int size);

  private:
    int fd;
    static const char* device;
    static uint8_t bits;
    static uint32_t speed;
    static uint16_t delay;
    static uint32_t mode;
};

#endif // SPI_H
