#include "AltimeterSource.h"
#include "PressureSource.h"
#include "InertiaSource.h"


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
    DataBridge(void);
    const FlightData GetFlightData() const;
    void On_HeightUpdate(const AltimeterSample &sample);
    void On_PressureUpdate(const PressureSample &sample);
    void On_InertiaUpdate(const InertiaSample &sample);
};

