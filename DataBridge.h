#ifndef DATABRIDGE_H
#define DATABRIDGE_H

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

class DataBridge
{
public:
    const FlightData GetFlightData() const;

private:
    void On_HeightUpdate(const AltimeterSample &sample);
    void On_PressureUpdate(const PressureSample &sample);
    void On_InertiaUpdate(const InertiaSample &sample);
};

#endif // DATABRIDGE_H
