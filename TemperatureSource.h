#ifndef TEMPERATURE_SOURCE_H
#define TEMPERATURE_SOURCE_H

#include <functional>

struct TemperatureSample {
    double temperature;
};

class TemperatureSource {
public:
    virtual void RegisterTemperatureReceiver(std::function<void(const TemperatureSample&)> callback_function);
    virtual const TemperatureSample SampleTemperature();

protected:
    virtual const double OnSampleTemperature() = 0;
private:
    void NotifySampleUpdate(const TemperatureSample& new_sample) const;
};

#endif // TEMPERATURE_SOURCE_H
