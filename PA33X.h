#ifndef PA33X_H
#define PA33X_H

#include "Sensor.h"
#include "SensorThread.h"
#include "PressureSource.h"

#include <functional>
#include <thread>
#include <atomic>

class PA33X : public Sensor, public PressureSource{
    public:
        PA33X();
        PA33X(const std::string& sensor_name, int ms);
        virtual void OnSample();
        virtual const PressureSample OnSamplePressure();
};

#endif // PA33X_H
