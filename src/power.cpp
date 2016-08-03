
#include "power.h"

namespace Power {

#define MAX17043_ADDRESS    0x36
#define SOC_REGISTER        0x04
#define MODE_REGISTER       0x06

void setup() {
    Wire.begin();
    Wire.setSpeed(9600);
    writeRegister(MODE_REGISTER, 0x40, 0x00);
}

void readRegister(byte startAddress, byte &MSB, byte &LSB) {

    Wire.beginTransmission(MAX17043_ADDRESS);
    Wire.write(startAddress);
    Wire.endTransmission(true);

    Wire.requestFrom(MAX17043_ADDRESS, 2, true);
    MSB = Wire.read();
    LSB = Wire.read();
}

void writeRegister(byte address, byte MSB, byte LSB) {

    Wire.beginTransmission(MAX17043_ADDRESS);
    Wire.write(address);
    Wire.write(MSB);
    Wire.write(LSB);
    Wire.endTransmission(true);
}

float getSoC() {

    byte MSB = 0;
    byte LSB = 0;

    readRegister(SOC_REGISTER, MSB, LSB);
    float decimal = LSB / 256.0;
    return MSB + decimal;

}

} // namespace Power
