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
    Sensor(const std::string& sensor_name) : sensor_name(sensor_name) {}
    //virtual ~Sensor();

    virtual void OnInitialize() =0; // in order to make the class abstract
    virtual void OnSample() = 0;
    virtual void OnTerminate() = 0;
private:
    std::string sensor_name;
};

#endif // SENSOR_H
