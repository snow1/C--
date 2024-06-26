#ifndef PA33X_H
#define PA33X_H

#include "Sensor.h"
#include "PressureSource.h"
#include <functional>
#include <thread>
#include <atomic>

class PA33X : public Sensor, public PressureSource{
    public:
        PA33X();
        PA33X(const std::string& sensor_name);
        ~PA33X();

        // PA33X(const PA33X&) = delete; // Disable copy constructor
        // PA33X& operator=(const PA33X&) = delete; // Disable copy assignment

        // PA33X(PA33X&&) noexcept; // Enable move constructor
        // PA33X& operator=(PA33X&&) noexcept; // Enable move assignment

        virtual void OnSample();
        virtual const PressureSample OnSamplePressure();

        void OnInitialize() override;
        void OnTerminate() override;

        void StartThread();
        void StopThread();
    private:
        std::atomic<bool> running;
        std::thread sampling_thread;
        void SampleLoop();

};

#endif // PA33X_H
