#ifndef PROTOKOL_H
#define PROTOKOL_H

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

class Protokol {
public:
    Protokol();
    ~Protokol();
    bool dispensePill(uint8_t id, uint8_t amount);

private:
    void transfer(uint8_t* command, uint8_t size);
    uint8_t checksum(uint8_t value);

    int fd;
    static const char* device;
    static uint8_t bits;
    static uint32_t speed;
    static uint16_t delay;
    static uint32_t mode;
};

#endif // PROTOKOL_H
