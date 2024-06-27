#include "MTi_30_AHRS.h"
#include <iostream>
using namespace std;

MTi_30_AHRS::MTi_30_AHRS(string sensor_name): Sensor(sensor_name, 1)
{
    //std::cout << "MTi_30_AHRS" <<std::endl;
}

MTi_30_AHRS::MTi_30_AHRS(): Sensor("MTi_30_AHRS", 1)
{
    //std::cout << "MTi_30_AHRS" <<std::endl;
    sensor_thread.StartThread();
}

void MTi_30_AHRS::OnSample(){
    SampleInertia();
}

const InertiaSample MTi_30_AHRS::OnSampleInertia(){
    InertiaSample sample;
    sample.x = 30.f;
    return sample;
}