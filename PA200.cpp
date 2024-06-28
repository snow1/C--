#include "PA200.h"

PA200::PA200(const std::string& name, int ms) : Sensor(name), sampling_interval(ms){
    
}

void PA200::OnSample(){
    SampleAltimeter();
}

void PA200::OnInitialize(){
}

void PA200::OnTerminate(){
}
const AltimeterSample PA200::OnSampleAltimeter(){
    struct AltimeterSample sample;
    sample.distance = 200;
    return sample;
}