#include "PA33X.h"

#include <iostream>
using namespace std;


PA33X::PA33X(const std::string& sensor_name, int ms) : Sensor(sensor_name), sampling_interval(ms), distribution(0.0, 1.0){
}

void PA33X::OnInitialize(){
    
}

void PA33X::OnTerminate(){
}

void PA33X::OnSample(){
    SamplePressure();
}

const PressureSample PA33X::OnSamplePressure() {
    PressureSample sample;
    sample.pressure = distribution(generator);
    return sample;
}