#include "PA33X.h"

PA33X::PA33X(const std::string& sensor_name) : Sensor(sensor_name, 2000){
    
}

PA33X::PA33X() : Sensor("PA33X", 2000){
    
}

void PA33X::OnSample(){
    SamplePressure();
}

const PressureSample PA33X::OnSamplePressure(){
    PressureSample sample;
    sample.pressure = 33;
    return sample;
}