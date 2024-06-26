#ifndef PRESSURE_SOURCE_H
#define PRESSURE_SOURCE_H

#include <functional>
#include <vector>
#include <iostream>

struct PressureSample {
public:
    double pressure;
};

class PressureSource {
private:
    void NotifySampleUpdate(const PressureSample& new_sample) const;
    std::vector<std::function<void(const PressureSample)>> callback_functions = {};
public:
    void RegisterPressureReceiver(std::function<void(const PressureSample&)> callback_function);
    const PressureSample SamplePressure();
protected:
    virtual const PressureSample OnSamplePressure() = 0;

};

#endif // PRESSURE_SOURCE_H
