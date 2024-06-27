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
    // m.lock();
    // dataBridge.GetFlightData();
    // m.unlock();

    // Simulate the main thread work
    //main thread calls every 500ms?

    while (true) {
            FlightData fd = dataBridge.GetFlightData();    
            this_thread::sleep_for(chrono::milliseconds(5000));
        }
   return 0;
    
}
// 