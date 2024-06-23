#ifndef PA200_H
#define PA200_H

#include "Sensor.h"
#include "AltimeterSource.h"
#include "ReportGenerator.h"


class PA200 : Sensor, AltimeterSource, ReportGenerator{

public:
    void RegisterAltimeterReceiver(std::function<void(const AltimeterSample)> callback_function);
    const AltimeterSample SampleAltimeter() const;
    DiagnosticReport GenerateReport() const;
    
};

#endif // PA200_H
