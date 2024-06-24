#ifndef SENSOR_H
#define SENSOR_H


#include "SensorThread.h"
#include <chrono>
#include <string>
#include <thread>

class Sensor {
public:
    Sensor(const std::string& sensor_name, int ms);
    ~Sensor();

    virtual void OnInitialize();
    virtual void OnSample() = 0;
    virtual void OnTerminate();
protected:
    std::string name;
    SensorThread* sensor_thread_;
    int ms;
};

#endif // SENSOR_H
