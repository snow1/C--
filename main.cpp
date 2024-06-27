#include <iostream>
#include "DataBridge.h"
#include "PA200.h"
#include "PA33X.h"
#include "MTi_30_AHRS.h"

#include <thread>
#include <mutex>
#include <memory>

using namespace std;
mutex m;

int main() { 
    auto pressure_source = make_unique<PA33X>();

    auto inertia_source = make_unique<MTi_30_AHRS>();
    auto altimeter_source = make_unique<PA200>();


    DataBridge dataBridge(m, move(inertia_source), move(altimeter_source), move(pressure_source));

    // Simulate the main thread work
    this_thread::sleep_for(chrono::milliseconds(500));

    // while (true) {
    //         FlightData fd = db.GetFlightData();
    //         m.lock();
    //         cout << "System: { " << fd.system_depth << ", " << fd.system_height << ", " << fd.water_column_depth << ", " << fd.roll << ", " << fd.pitch << ", " << fd.heading << " }" << endl;
    //         m.unlock();
            
    //         this_thread::sleep_for(chrono::milliseconds(500));
    //     }
   return 0;
    
}
