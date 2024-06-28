// DataBridge.h
#ifndef DATABRIDGE_H
#define DATABRIDGE_H

#include <mutex>
#include <memory> // Add this line to include the <memory> header file
#include "SensorThread.h"
#include "AltimeterSource.h"
#include "PressureSource.h"
#include "InertiaSource.h"
struct FlightData
{
public:
    double system_depth;
    double system_height;
    double water_column_depth;
    double roll;
    double pitch;
    double heading;
};
class DataBridge {
public:
    DataBridge(std::mutex& m, std::shared_ptr<InertiaSource> inertia, std::shared_ptr<AltimeterSource> altimeter, std::shared_ptr<PressureSource> pressure);
    const FlightData GetFlightData() const;
   

private:
    std::shared_ptr<InertiaSource> inertia_source;
    std::shared_ptr<AltimeterSource> altimeter_source;
    std::shared_ptr<PressureSource> pressure_source;
    std::mutex& m;

    void On_HeightUpdate(const AltimeterSample &sample);
    void On_PressureUpdate(const PressureSample &sample);
    void On_InertiaUpdate(const InertiaSample &sample);
};

#endif // DATABRIDGE_H

