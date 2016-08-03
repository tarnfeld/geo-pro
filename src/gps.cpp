/**
 * 
 */

#include "gps.h"
#include "TinyGPS/TinyGPS.h"

namespace GPS {

void setup() {
    Serial1.begin(9600);
}

std::string readPosition(unsigned long timeoutMs) {
    TinyGPS gps;
    bool isValidGPS;
    for (unsigned long start = millis(); millis() - start < 1000;){
        // Check GPS data is available
        while (Serial1.available()){
            char c = Serial1.read();
            
            // parse GPS data
            if (gps.encode(c))
                isValidGPS = true;
        }
    }

    char coords[64];
    std::string str;

    if (isValidGPS) {
        float lat, lon;
        unsigned long age;
    
        gps.f_get_position(&lat, &lon, &age);
        sprintf(coords, "%.6f,%.6f",
                (lat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : lat),
                (lon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : lon));

        str.append(coords);
    }

    return str;
}

}

