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

    MTi_30_AHRS inertia;
    PA200 altimeter;
   // PA33X pressure_source("PA33X"); // Sampling every 2000 ms (2 seconds)

    DataBridge dataBridge(m, inertia, altimeter, move(pressure_source));

    // Simulate the main thread work
    std::this_thread::sleep_for(std::chrono::seconds(25));

    cout<< inertia.OnSampleInertia().x << endl;

    // while (true) {
    //         FlightData fd = db.GetFlightData();
    //         m.lock();
    //         cout << "System: { " << fd.system_depth << ", " << fd.system_height << ", " << fd.water_column_depth << ", " << fd.roll << ", " << fd.pitch << ", " << fd.heading << " }" << endl;
    //         m.unlock();
            
    //         this_thread::sleep_for(chrono::milliseconds(500));
    //     }
   this_thread::sleep_for(chrono::milliseconds(5000));
   return 0;
    
}
