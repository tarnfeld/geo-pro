
#include "application.h"

#ifndef POWER_
#define POWER_

namespace Power {
    void setup();
    float getSoC();
    void readRegister(byte startAddress, byte &MSB, byte &LSB);
    void writeRegister(byte address, byte MSB, byte LSB);
}

#endif
