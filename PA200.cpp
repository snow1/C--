#include "PA200.h"

PA200::PA200(const std::string& name) : Sensor(name, 3){
    
}

PA200::PA200() : Sensor("PA200", 3){
    
}

void PA200::OnSample(){
    SampleAltimeter();
}

const AltimeterSample PA200::OnSampleAltimeter(){
    struct AltimeterSample sample;
    sample.distance = 200;
    return sample;
}