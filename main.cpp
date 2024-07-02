// main.cpp
#include "DataBridge.h"
#include "PA33X.h"
#include "PA200.h"
#include "MTi_30_AHRS.h"
#include "SensorThread.h"
#include <mutex>
#include <vector>

std::mutex m;

int main() {

    auto inertia_sensor = std::make_shared<MTi_30_AHRS>("MTi_30_AHRS", 1000);
    auto altimeter_sensor = std::make_shared<PA200>("PA200", 3000);
    auto pressure_sensor = std::make_shared<PA33X>("PA33X", 2000);

    DataBridge data_bridge(m, inertia_sensor, altimeter_sensor, pressure_sensor);

    std::vector<std::shared_ptr<SensorThread>> sensor_threads;
    sensor_threads.push_back(std::make_shared<SensorThread>(inertia_sensor));
    sensor_threads.push_back(std::make_shared<SensorThread>(altimeter_sensor));
    sensor_threads.push_back(std::make_shared<SensorThread>(pressure_sensor));


    while (true)
    {
        for (auto &thread : sensor_threads)
        {
            thread->StartThread();
        }
        data_bridge.GetFlightData();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        for (auto &thread : sensor_threads)
        {
            thread->StopThread();
        }
    }

    return 0;
}
