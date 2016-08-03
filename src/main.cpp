/**
 * 
 */

#include "power.h"
#include "gps.h"
#include "SD/sd-card-library-photon-compat.h"

const uint8_t chipSelect = A2;
const uint8_t mosiPin = A5;
const uint8_t misoPin = A4;
const uint8_t clockPin = A3;

void setup() {
    Power::setup();
    GPS::setup();

    // Write the location to the SD card
    if (!SD.begin(mosiPin, misoPin, clockPin, chipSelect)) {
        Particle.publish("sderr", "Card failed, or not present.");
    }
}

void loop() {

    // Print the battery percentage!
    float charge = Power::getSoC();
    Particle.publish("batteryPercentage", String(charge));

    // Read out some GPS data
    std::string pos = GPS::readPosition(1000);
    Particle.publish("gpsdata", pos.c_str());

    File dataFile = SD.open("gps-coords.txt", FILE_WRITE);
    if (dataFile) {
        dataFile.seek(dataFile.size()); // Move to the end of the file
        dataFile.println(pos.c_str());
        dataFile.flush();
        dataFile.close();
    }

    delay(5 * 1000);
}
