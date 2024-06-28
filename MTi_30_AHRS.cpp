#include "MTi_30_AHRS.h"
#include <iostream>
using namespace std;

MTi_30_AHRS::MTi_30_AHRS(string sensor_name, int ms): Sensor(sensor_name), sampling_interval(ms)
{
}

void MTi_30_AHRS::OnInitialize(){
}
void MTi_30_AHRS::OnTerminate(){
}   

void MTi_30_AHRS::OnSample(){
    SampleInertia();
}

const InertiaSample MTi_30_AHRS::OnSampleInertia(){
    InertiaSample sample;
    sample.x = 30.f;
    return sample;
}