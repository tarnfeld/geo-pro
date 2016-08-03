
#include "application.h"
#include <string>

#ifndef GPS_
#define GPS_

namespace GPS {
    void setup();
    std::string readPosition(unsigned long timeoutMs);
}

#endif
