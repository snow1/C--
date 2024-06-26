#include "SensorThread.h"
#include<iostream>


SensorThread::SensorThread(unique_ptr<Sensor> sensor_ptr) : sensor_ptr(move(sensor_ptr)), running(false) {

}

void SensorThread::startThread(){
    running = true;
    try{
        sensor_ptr->OnInitialize();
        while(running){
            sensor_ptr->OnSample();
        }
    }
    catch(exception& e){
        cout << "Exception: " << e.what() << endl;
    }
    sensor_ptr->OnTerminate();
}

    

void SensorThread::stopThread() {
    running = false;
}