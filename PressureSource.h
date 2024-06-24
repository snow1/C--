#ifndef PRESSURE_SOURCE_H
#define PRESSURE_SOURCE_H

#include <functional>
#include <vector>

struct PressureSample {
public:
    double pressure;
};

class PressureSource {
public:
    void RegisterPressureReceiver(std::function<void(const PressureSample&)> callback_function);
    const PressureSample SamplePressure();
    std::vector<std::function<void(const PressureSample)>> callback_functions={};

protected:
    virtual const PressureSample OnSamplePressure() = 0;
private:
    void NotifySampleUpdate(const PressureSample& new_sample) const;
};

#endif // PRESSURE_SOURCE_H
