#ifndef PA200_H
#define PA200_H

#include "Sensor.h"
#include "AltimeterSource.h"
#include "ReportGenerator.h"
#include "SensorThread.h"


class PA200 :public Sensor, public AltimeterSource {
    public:
        PA200(const std::string& name, int ms);
        PA200() = default;
        virtual void OnSample();
        virtual const AltimeterSample OnSampleAltimeter();
        void OnInitialize() override;
        void OnTerminate() override;
    private:
        int sampling_interval;
};

#endif // PA200_H
