#include "Sensor.h"
using namespace std;

Sensor::Sensor() {    
}


Sensor::Sensor(const std::string& sensor_name, int ms) : name(sensor_name), ms(ms){
    
}


Sensor::~Sensor() {
    
}

void Sensor::OnInitialize() {
    t = thread([this](){
        while (true) {
            this->OnSample();
            this_thread::sleep_for(chrono::milliseconds(ms));
        }
    });

}

void Sensor::OnTerminate() {
    t.join();
}

