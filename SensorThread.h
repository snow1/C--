#ifndef SensorThread_H
#define SensorThread_H

#include "Sensor.h"

#include <thread>
#include <chrono>
#include <functional>
#include <vector>
#include <atomic>
using namespace std;

 class SensorThread
 {
    private:
        atomic<bool> running;
        unique_ptr<Sensor> sensor_uni;
        thread thread;
        void ThreadLoop();

    public:
        SensorThread(unique_ptr<Sensor> sensor_ptr);
        ~SensorThread();
        void StartThread();
        void StopThread();
};

#endif // SensorThread_H