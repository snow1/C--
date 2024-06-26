#include <iostream>
#include "DataBridge.h"
#include "PA200.h"
#include "PA33X.h"
#include "MTi_30_AHRS.h"
#include "Sensor.h"
#include "AltimeterSource.h"
#include "InertiaSource.h"
#include "PressureSource.h"
#include <thread>
#include <mutex>

using namespace std;
mutex m;

int main() {
    cout << "Hi" << endl;
    DataBridge db(m);
    AltimeterSample as;
    InertiaSample is;
    PressureSample ps;
    while (true) {
            FlightData fd = db.GetFlightData();
            m.lock();
            cout << "System: { " << fd.system_depth << ", " << fd.system_height << ", " << fd.water_column_depth << ", " << fd.roll << ", " << fd.pitch << ", " << fd.heading << " }" << endl;
            m.unlock();
            db.On_HeightUpdate(as);
            db.On_InertiaUpdate(is);
            db.On_PressureUpdate(ps);
            
            this_thread::sleep_for(chrono::milliseconds(500));
        }
   
    
}
