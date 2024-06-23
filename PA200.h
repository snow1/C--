#ifndef PA200_H
#define PA200_H

#include "Sensor.h"
#include "AltimeterSource.h"
#include "ReportGenerator.h"


class PA200 : Sensor, AltimeterSource, ReportGenerator{

PA200(const std::string& name);

    void OnInitialize();  
    void OnSample() override; 
    void OnTerminate();  

    void RegisterAltimeterReceiver(std::function<void(const std::string&)> callback_function); 
    std::string SampleAltimeter();  
    virtual DiagnosticReport GenerateReport();  


    protected:
    std::string OnSampleAltimeter();  
    private:
    void NotifySampleUpdate(const std::string& new_sample) const;  


    
};

#endif // PA200_H
