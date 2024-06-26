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
    virtual ~Sensor()=default;

    virtual void OnInitialize();
    virtual void OnSample() = 0;
    virtual void OnTerminate();
    const std::string& GetName() const;
    int GetSampleInterval() const;
protected:
    std::string name;
    int ms;
};

#endif // SENSOR_H
