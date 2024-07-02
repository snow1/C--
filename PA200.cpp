#include "PA200.h"

PA200::PA200(const std::string& name, int ms) : Sensor(name), sampling_interval(ms), distribution(0.0, 1.0){
    
}

void PA200::OnSample(){
    SampleAltimeter();
}

void PA200::OnInitialize(){
}

void PA200::OnTerminate(){
}
const AltimeterSample PA200::OnSampleAltimeter(){
    AltimeterSample sample;
    sample.distance = distribution(generator);
    return sample;
}