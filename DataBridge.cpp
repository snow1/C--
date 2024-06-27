#include "DataBridge.h"
#include <iostream>
#include <mutex>

using namespace std;


DataBridge::DataBridge(mutex& m, unique_ptr<MTi_30_AHRS> inertia, unique_ptr<PA200> altimeter, unique_ptr<PA33X> pressure)
:m(m), inertia_source(move(inertia)), altimeter_source(move(altimeter)), pressure_source(move(pressure)){
    cout << "DataBridge Constructor" <<endl;

    pressure_source->RegisterPressureReceiver(
       bind(&DataBridge::On_PressureUpdate, this, placeholders::_1)
    );

    pressure_thread = make_unique<SensorThread>(move(pressure_source));
    pressure_thread->StartThread();


    inertia_source->RegisterInertiaReceiver(
        bind(&DataBridge::On_InertiaUpdate, this, placeholders::_1)
    );
    inertia_thread = make_unique<SensorThread>(move(inertia_source));
    inertia_thread->StartThread();

    altimeter_source->RegisterAltimeterReceiver(
        bind(&DataBridge::On_HeightUpdate, this, placeholders::_1)
    );
    altimeter_thread = make_unique<SensorThread>(move(altimeter_source));
    altimeter_thread->StartThread();

   
}


const FlightData DataBridge::GetFlightData() const{
    //initialize FlightData
    FlightData flight_data;
    flight_data.system_depth = 0.4;
    flight_data.system_height = 0.6;
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
    m.lock();
    cout << "Inertia Update: " << sample.x << endl;
    m.unlock();
}

