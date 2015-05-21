#ifndef PROTOKOL_H
#define PROTOKOL_H

#include "spi.h"

class Protokol {
  public:
    Protokol();
    ~Protokol();
    bool open();
    bool close();
    bool dispensePill(unsigned int id, unsigned int amount);

  private:
    enum {
        PROTOKOL_OPEN = 0x01,
        PROTOKOL_CLOSE = 0x0A,
        PROTOKOL_DISPENSE = 0x14
    };

    enum {
        PROTOKOL_REPLY_OPEN_OK = 0x01,
        PROTOKOL_REPLY_OPEN_ERR = 0x02
    };

    unsigned char checksum(unsigned char value);
    SPI interface_;
};

#endif // PROTOKOL_H
