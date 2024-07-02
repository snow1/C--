#ifndef MTI_30_AHRS_H
#define MTI_30_AHRS_H

#include "Sensor.h"
#include "InertiaSource.h"
#include "ReportGenerator.h"
#include "SensorThread.h"
#include <thread>
#include <iostream>
#include <random>


using namespace std;

class MTi_30_AHRS : public Sensor, public InertiaSource {
public:
    MTi_30_AHRS(string sensor_name, int ms);
    MTi_30_AHRS()=default;
    virtual void OnSample();
    virtual const InertiaSample OnSampleInertia();
    void OnInitialize() override;
    void OnTerminate() override;
private:
    int sampling_interval;
    default_random_engine generator; // Random number generator
    uniform_real_distribution<float> distribution; // Distribution for random numbers
};

#endif // MTI_30_AHRS_H
