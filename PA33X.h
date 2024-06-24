#ifndef PA33X_H
#define PA33X_H

#include "Sensor.h"
#include "PressureSource.h"
#include "ReportGenerator.h"
#include "TemperatureSource.h"
#include <functional>

class PA33X : public Sensor, public PressureSource{
    public:
        PA33X();
        PA33X(const std::string& sensor_name);
        virtual void OnSample();
        virtual const PressureSample OnSamplePressure();
};

#endif // PA33X_H
