// #include "SensorThread.h"
// #include<iostream>

// using namespace std;

// SensorThread::SensorThread() {
// }

// void SensorThread::startThread(int ms, std::function<void()> callback_function){
//     running = true;
//     t = thread([this, ms, callback_function](){
//         while(running){
//             callback_function();
//             this_thread::sleep_for(chrono::milliseconds(ms));
//            // cout << "Thread is running" << endl;
//         }
//     });
// }

    

// void SensorThread::stopThread() {
//     running = false;
//     t.join();// wait for the thread to finish
// }