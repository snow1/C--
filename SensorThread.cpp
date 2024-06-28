#include "SensorThread.h"
#include <chrono>
#include <iostream>

SensorThread::SensorThread(std::shared_ptr<Sensor> sensor_ptr)
    : sensor(sensor_ptr), running(false) {
    }


SensorThread::~SensorThread() {
    StopThread();
}

void SensorThread::StartThread() {
    if (!running.exchange(true)) {
        sampling_thread = std::thread(&SensorThread::SampleLoop, this);
    }
}

void SensorThread::StopThread() {
    running = false;
    if (sampling_thread.joinable()) {
        sampling_thread.join();
    }
}

void SensorThread::SampleLoop() {
    sensor->OnInitialize();

    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        sensor->OnSample();
    }

    sensor->OnTerminate();
}


// void SensorThread::startThread(){
//     t = thread([this]() {
//         running = true;
//         try{
//             sensor_uni->OnInitialize();
//             cout << "Thread started" << endl;
            
//                 while (running)
//                 {
//                     sensor_uni->OnSample();
//                     this_thread::sleep_for(chrono::milliseconds(sensor_uni->ms));
//                 }
            

//             }
//         catch(exception& e){
//             cout << "Exception: " << e.what() << endl;
//         }
//         sensor_uni->OnTerminate();
//     });
// }

    