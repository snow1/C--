#include "DataBridge.h"
#include <iostream>
#include <mutex>

using namespace std;


DataBridge::DataBridge(mutex& m): m(m) {
    inertia_source.RegisterInertiaReceiver(
        [this](const InertiaSample &sample){
            this->On_InertiaUpdate(sample);
        }
    );
    altimeter_source.RegisterAltimeterReceiver(
        [this](const AltimeterSample &sample){
            this->On_HeightUpdate(sample);
        }
    );
    pressure_source.RegisterPressureReceiver(
        [this](const PressureSample &sample){
            this->On_PressureUpdate(sample);
        }
    );
}


const FlightData DataBridge::GetFlightData() const{
    //initialize FlightData
    FlightData flight_data;
    flight_data.system_depth = 0;
    flight_data.system_height = 0;
    flight_data.water_column_depth = 0;
    flight_data.roll = 0;
    flight_data.pitch = 0;
    flight_data.heading = 0;
    return flight_data;
}

void DataBridge::On_HeightUpdate(const AltimeterSample &sample){
    m.lock();
    cout << "Height Update: " << sample.distance << endl;
    m.unlock();
}

void DataBridge::On_PressureUpdate(const PressureSample &sample){
    m.lock();
    cout << "Pressure Update: " << sample.pressure << endl;
    m.unlock();
}

void DataBridge::On_InertiaUpdate(const InertiaSample &sample){
    // lock
    m.lock();
    cout << "Inertia Update: " << sample.x << endl;
    m.unlock();
    // unlock
}

