#ifndef PA33X_H
#define PA33X_H

#include "Sensor.h"
#include "PressureSource.h"
#include "ReportGenerator.h"
#include "TemperatureSource.h"
#include <functional>

class PA33X : Sensor, PressureSource, TemperatureSource, ReportGenerator{

};

#endif // PA33X_H
