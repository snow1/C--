#include "MTi_30_AHRS.h"
#include <iostream>
using namespace std;

MTi_30_AHRS::MTi_30_AHRS(string sensor_name): Sensor(sensor_name, 1000)
{
    //std::cout << "MTi_30_AHRS" <<std::endl;
}

MTi_30_AHRS::MTi_30_AHRS(): Sensor("MTi_30_AHRS", 1000)
{
    //std::cout << "MTi_30_AHRS" <<std::endl;
}

void MTi_30_AHRS::OnSample(){
    SampleInertia();
}

const InertiaSample MTi_30_AHRS::OnSampleInertia(){
    InertiaSample sample;
    sample.x = 3;
    return sample;
}