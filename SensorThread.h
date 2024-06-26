#ifndef SENSOR_THREAD_H
#define SENSOR_THREAD_H

#include <memory>
#include <thread>
#include <atomic>
#include "Sensor.h"

class SensorThread {
public:
    SensorThread(std::unique_ptr<Sensor> sensor_ptr);
    SensorThread();
    ~SensorThread();

    void StartThread();
    void StopThread();

private:
    std::unique_ptr<Sensor> sensor;
    std::atomic<bool> running;
    std::thread sampling_thread;

    void SampleLoop();
};

#endif // SENSOR_THREAD_H
