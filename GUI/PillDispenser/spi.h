#ifndef SPI_H
#define SPI_H

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

class SPI {
  public:
    SPI();
    ~SPI();
    int transfer(unsigned char* command, size_t size);
    int recieve(unsigned char* command, size_t size);

  private:
    void openSPI();
    void closeSPI();

    int fd;
    const char* device;
    unsigned char bits;
    unsigned short delay;
    unsigned long speed;
    unsigned long mode;
};

#endif // SPI_H
