#include "Sensor.h"
#include <iostream>

Sensor::Sensor(const std::string& sensor_name, int ms) : name(sensor_name), ms(ms) {
}

void Sensor::OnInitialize() {
    std::cout << name << " initialized with sampling rate: " << ms << " ms." << std::endl;
}

void Sensor::OnTerminate() {
    std::cout << name << " terminated." << std::endl;
}
