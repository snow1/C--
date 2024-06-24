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

int main() {
    cout << "DataBridge" << endl;
    DataBridge db = DataBridge();
   // MTi_30_AHRS mti = MTi_30_AHRS("name");
    


    // mutex display_mutex;
    // display_mutex.lock();
    // cout << "DataBridge" << endl;
    // DataBridge db;
    // display_mutex.unlock();
}
