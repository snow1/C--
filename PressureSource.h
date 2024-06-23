#ifndef PRESSURE_SOURCE_H
#define PRESSURE_SOURCE_H

#include <functional>

struct PressureSample {
public:
    double pressure;
};

class PressureSource {
public:
    void RegisterPressureReceiver(std::function<void(const PressureSample&)> callback_function);
    const PressureSample SamplePressure();

protected:
    virtual const double OnSamplePressure() = 0;
private:
    void NotifySampleUpdate(const PressureSample& new_sample) const;
};

#endif // PRESSURE_SOURCE_H
