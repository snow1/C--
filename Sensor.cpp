#include "Sensor.h"

Sensor::Sensor(const std::string& sensor_name) : name(sensor_name) {}

Sensor::~Sensor() {}

void Sensor::OnInitialize() {
    // Default initialization code
}

void Sensor::OnTerminate() {
    // Default termination code
}
