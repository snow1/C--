#include "Sensor.h"


Sensor::Sensor(const std::string& sensor_name, int ms): name(sensor_name), ms(ms) {}


void Sensor::OnInitialize() {}
void Sensor::OnTerminate() {}

const std::string& Sensor::GetName() const {
    return name;
}

int Sensor::GetSampleInterval() const {
    return ms;
}