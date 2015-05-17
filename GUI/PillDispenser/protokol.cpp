#include "protokol.h"

Protokol::Protokol(SPI* interface) : interface_(interface) {}

Protokol::~Protokol() { delete interface_; }

unsigned int Protokol::checksum(unsigned int value) {
    // Two's complement
    return ~(value + 1);
}

bool Protokol::open() {
    unsigned int command[2];

    command[0] = PROTOKOL_OPEN;
    command[1] = checksum(command[0]);

    interface_->transfer(command, 2);
    interface_->recieve(command, 2);
    if (command[0] == PROTOKOL_REPLY_ERR && command[1] == checksum(command[1]))
        return true;

    return false;
}

bool Protokol::close() {
    unsigned int command[2];

    command[0] = PROTOKOL_CLOSE;
    command[1] = checksum(command[0]);

    interface_->transfer(command, 2);
    interface_->recieve(command, 2);
    if (command[0] == PROTOKOL_REPLY_ERR && command[1] == checksum(command[1]))
        return true;

    return false;
}

bool Protokol::dispensePill(unsigned int id, unsigned int amount) {
    unsigned int size = 6;
    unsigned int command[size];

    // Dispense command
    command[0] = PROTOKOL_DISPENSE;

    // Pill identifier
    command[2] = id;

    // Amount of pill identifier
    command[4] = amount;

    // Setup the checksums
    for (int i = 1; i < size; i + 2)
        command[i] = checksum(command[i - 1]);

    // Do the transfers
    for (int i = 0; i < size; i + 2)
        interface_->transfer(&command[i], 2);

    return true;
}
