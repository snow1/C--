#include <mutex>
#include "SensorThread.h"
#include "MTi_30_AHRS.h"
#include "PA200.h"
#include "PA33X.h"

typedef struct FlightData
{
public:
    double system_depth;
    double system_height;
    double water_column_depth;
    double roll;
    double pitch;
    double heading;
}FlightData;

class DataBridge
{
public:
    DataBridge(mutex& m, MTi_30_AHRS& inertia, PA200& altimeter, unique_ptr<PA33X> pressure);

    const FlightData GetFlightData() const;
    void On_HeightUpdate(const AltimeterSample &sample);
    void On_PressureUpdate(const PressureSample &sample);
    void On_InertiaUpdate(const InertiaSample &sample);

private:
    MTi_30_AHRS& inertia_source;
    PA200& altimeter_source;
    //PA33X& pressure_source;
    unique_ptr<PA33X> pressure_source;


    std::unique_ptr<SensorThread> pressure_thread;
    mutex& m;
};
