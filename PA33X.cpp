#include "PA33X.h"

#include <iostream>
using namespace std;

// PA33X::PA33X() : Sensor("PA33X", 1), sensor_thread(SensorThread(std::make_unique<void>(*this))) {
//     sensor_thread.StartThread();
// }

// PA33X::PA33X(const std::string& sensor_name, int ms) : Sensor(sensor_name, ms), 
// sensor_thread(SensorThread(std::make_unique<void>(*this))) {
//     sensor_thread.StartThread();
// }

PA33X::PA33X() : Sensor("PA33X", 1) {
    cout<<"PA33X"<<endl;
    sensor_thread.StartThread();
}

PA33X::PA33X(const std::string& sensor_name, int ms) : Sensor(sensor_name, ms){
    cout<<"PA33X11"<<endl;

    sensor_thread.StartThread();
}


PA33X::~PA33X() {
}

void PA33X::OnInitialize() {
    
}


void PA33X::OnTerminate() {

}

void PA33X::OnSample(){
    SamplePressure();
}

const PressureSample PA33X::OnSamplePressure() {
    PressureSample sample;
    sample.pressure = 33;
    return sample;
}