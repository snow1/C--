#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include "DataBridge.h"

class FlightController {
    DataBridge dataBridge;
public:
    void Control();
};

#endif // FLIGHTCONTROLLER_H
