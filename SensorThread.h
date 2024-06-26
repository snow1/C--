#ifndef SensorThread_H
#define SensorThread_H

#include "Sensor.h"

#include <thread>
#include <chrono>
#include <functional>
#include <vector>
using namespace std;

 class SensorThread
 {
    private:
        bool running;
        unique_ptr<Sensor> sensor_ptr;

    public:
        SensorThread(unique_ptr<Sensor> sensor_ptr);
        ~SensorThread() = default;
        void startThread();
        void stopThread();
};

#endif // SensorThread_H