#include "PA200.h"

PA200::PA200(const std::string& name) : Sensor(name, 3000){
    
}

void PA200::OnSample(){
    SampleAltimeter();
}

const AltimeterSample PA200::OnSampleAltimeter(){
    AltimeterSample sample;
    sample.distance = 200;
    return sample;
}