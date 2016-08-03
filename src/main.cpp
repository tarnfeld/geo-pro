/**
 * 
 */

#include "power.h"
#include "gps.h"

void setup() {
    Power::setup();
    GPS::setup();
}

void loop() {

    // Print the battery percentage!
    float charge = Power::getSoC();
    Particle.publish("batteryPercentage", String(charge));

    // Read out some GPS data
    std::string pos = GPS::readPosition(1000);
    Particle.publish("gpsdata", pos.c_str());

    delay(5 * 1000);

    System.sleep(SLEEP_MODE_DEEP, 30);
}
