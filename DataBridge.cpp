#include "DataBridge.h"
#include <iostream>
#include <mutex>

using namespace std;

DataBridge::DataBridge(){
    //register the DataBridge as a listener for the AltimeterSource
    
}


const FlightData DataBridge::GetFlightData() const{
    cout << "GetFlightData" << endl;
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

    cout << "Height Update: " << sample.distance << endl;
}

void DataBridge::On_PressureUpdate(const PressureSample &sample){

    cout << "Pressure Update: " << sample.pressure << endl;
}

void DataBridge::On_InertiaUpdate(const InertiaSample &sample){

    cout << "Inertia Update: " << sample.x << endl;
}

