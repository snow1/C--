#ifndef PA200_H
#define PA200_H

#include "Sensor.h"
#include "AltimeterSource.h"
#include <random>



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
        std::default_random_engine generator; // Random number generator
        std::uniform_real_distribution<float> distribution; // Distribution for random numbers
};

#endif // PA200_H
