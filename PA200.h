#ifndef PA200_H
#define PA200_H

#include "Sensor.h"
#include "AltimeterSource.h"
#include "ReportGenerator.h"


class PA200 :public Sensor,public AltimeterSource{
    PA200();
    ~PA200();
    PA200(const std::string& name);
    virtual void OnSample();
    virtual const AltimeterSample OnSampleAltimeter();
        
};

#endif // PA200_H
