#include "SensorThread.h"
#include <chrono>
#include <iostream>

SensorThread::SensorThread(std::unique_ptr<Sensor> sensor_ptr)
    : sensor(std::move(sensor_ptr)) {}

SensorThread::SensorThread() {}


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
        std::this_thread::sleep_for(std::chrono::milliseconds(sensor->GetSampleInterval()));
        sensor->OnSample();

        // Simulate failure after 10 samples
        static int sample_count = 0;
        if (++sample_count >= 10) {
            std::cout << sensor->GetName() << " reporting failure after 10 samples." << std::endl;
            break;
        }
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

    