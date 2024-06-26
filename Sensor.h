#ifndef SENSOR_H
#define SENSOR_H

#include <thread>
#include <chrono>
#include <string>
#include <functional>
#include <vector>


class Sensor {
public:
    // Sensor();
    Sensor(const std::string& sensor_name, int ms);
    ~Sensor()=default;

    virtual void OnInitialize();
    virtual void OnSample() = 0;
    virtual void OnTerminate();
protected:
    std::string name;
    int ms;
};

#endif // SENSOR_H
