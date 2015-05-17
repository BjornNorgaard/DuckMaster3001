#ifndef PROTOKOL_H
#define PROTOKOL_H

#include "spi.h"

class Protokol {
  public:
    Protokol(SPI* interface = new SPI);
    ~Protokol();
    bool open();
    bool close();
    bool dispensePill(unsigned int id, unsigned int amount);

  private:
    enum {
        PROTOKOL_OPEN = 0x01,
        PROTOKOL_CLOSE = 0x02,
        PROTOKOL_DISPENSE = 0x03
    };

    enum {
        PROTOKOL_REPLY_ACK = 0x01,
        PROTOKOL_REPLY_ERR = 0x02
    };

    unsigned int checksum(unsigned int value);
    SPI* interface_;
};

#endif // PROTOKOL_H
