#include "protokol.h"

Protokol::Protokol() {}

unsigned char Protokol::checksum(unsigned char value) {
    // Two's complement
    return ~(value) + 1;
}

bool Protokol::open() {
    unsigned char command[2];

    command[0] = PROTOKOL_OPEN;
    command[1] = checksum(command[0]);

    interface_.transfer(command, 2);

    // Needs confimation

    return false;
}

bool Protokol::close() {
    unsigned char command[2];

    command[0] = PROTOKOL_CLOSE;
    command[1] = checksum(command[0]);

    interface_.transfer(command, 2);

    // Needs confirmation

    return false;
}

bool Protokol::dispensePill(unsigned int id, unsigned int amount) {
    size_t size = 6;
    unsigned char command[size];

    // Dispense command
    command[0] = PROTOKOL_DISPENSE;

    // Pill identifier
    command[2] = id;

    // Amount of pill identifier
    command[4] = amount;

    // Setup the checksums
    for (size_t i = 1; i < size; i = i + 2)
      command[i] = checksum(command[i - 1]);

    // Do the transfers
    interface_.transfer(command, 6);

    // Needs confirmation

    return true;
}
