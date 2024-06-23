#ifndef SENSOR_H
#define SENSOR_H

#include <string>

class Sensor {
public:
    Sensor(const std::string& sensor_name);
    virtual ~Sensor();

    virtual void OnInitialize();
    virtual void OnSample() = 0;
    virtual void OnTerminate();
protected:
    std::string name;
};

#endif // SENSOR_H
