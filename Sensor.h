#ifndef SENSOR_H
#define SENSOR_H

#include <string>
using std::string;

class Sensor {
public:
    Sensor(const std::string& sensor_name);
    virtual ~Sensor();

    virtual void OnInitialize();
    virtual void OnSample() = 0;
    virtual void OnTerminate();
};

#endif // SENSOR_H
