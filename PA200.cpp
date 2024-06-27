#include "PA200.h"

PA200::PA200(const std::string& name) : Sensor(name, ms){
    
}

PA200::PA200() : Sensor("PA200", 3000){
}

void PA200::OnSample(){
    SampleAltimeter();
}

const AltimeterSample PA200::OnSampleAltimeter(){
    struct AltimeterSample sample;
    sample.distance = 200;
    return sample;
}