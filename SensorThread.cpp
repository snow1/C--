#include "SensorThread.h"
#include <iostream>
#include <chrono>
#include <thread>


SensorThread::SensorThread(unique_ptr<Sensor> sensor_ptr) : sensor_uni(move(sensor_ptr)), running(false) {
}


SensorThread::~SensorThread(){
    cout << "Thread stopped" << endl;
    StopThread();
}

void SensorThread::StartThread() {
    running = true;
    thread = std::thread(&SensorThread::ThreadLoop, this);
}

void SensorThread::StopThread() {
    running = false;
    if (thread.joinable()) {
        thread.join();
    }
}

void SensorThread::ThreadLoop() {
    sensor_uni->OnInitialize();

    while (running) {
        sensor_uni->OnSample();
       // std::this_thread::sleep_for(std::chrono::milliseconds(sensor_uni->ms));
    }

    sensor_uni->OnTerminate();
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

    