// #include "AltimeterSource.h"
// #include "PressureSource.h"
// #include "InertiaSource.h"
// #include "MTi_30_AHRS.h"
// #include "PA200.h"
// #include "PA33X.h"
// #include <mutex>


// typedef struct FlightData
// {
// public:
//     double system_depth;
//     double system_height;
//     double water_column_depth;
//     double roll;
//     double pitch;
//     double heading;
// }FlightData;

// class DataBridge
// {
// public:
//     DataBridge(mutex& m);

//     const FlightData GetFlightData() const;
//     void On_HeightUpdate(const AltimeterSample &sample);
//     void On_PressureUpdate(const PressureSample &sample);
//     void On_InertiaUpdate(const InertiaSample &sample);

//     private:
//         MTi_30_AHRS inertia_source;
//         PA200 altimeter_source;
//         PA33X pressure_source;
//         mutex& m;
// };

