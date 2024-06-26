#include "PA33X.h"

PA33X::PA33X() : Sensor("PA33", 1), running(false) {}

PA33X::PA33X(const std::string& sensor_name) : Sensor("PA33", 1), running(false) {}


PA33X::~PA33X() {
    StopThread();
}
// PA33X::PA33X() : Sensor("PA33X", 2){
//     //start the thread from the sensorThread class
//     SensorThread sensorThread(PA33X::OnSamplePressure);
//     sensorThread.startThread();
    
// }

// PA33X::PA33X(PA33X&& other) noexcept
//     : Sensor(std::move(other)), PressureSource(std::move(other)), running(other.running.load()), sampling_thread(std::move(other.sampling_thread)) {
//     other.running = false;
// }

// PA33X& PA33X::operator=(PA33X&& other) noexcept {
//     if (this != &other) {
//         StopThread();
//         Sensor::operator=(std::move(other));
//         PressureSource::operator=(std::move(other));
//         running = other.running.load();
//         sampling_thread = std::move(other.sampling_thread);
//         other.running = false;
//     }
//     return *this;
// }


void PA33X::OnInitialize() {
    Sensor::OnInitialize();
}


void PA33X::OnTerminate() {
    Sensor::OnTerminate();
}

void PA33X::StartThread() {
    running = true;
    sampling_thread = std::thread(&PA33X::SampleLoop, this);
}

void PA33X::StopThread() {
    running = false;
    if (sampling_thread.joinable()) {
        sampling_thread.join();
    }
}

void PA33X::SampleLoop() {
    int sample_count = 0;
    OnInitialize();

    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        OnSample();

        if (++sample_count >= 10) {
            std::cout << name << " reporting failure after 10 samples." << std::endl;
            break;
        }
    }

    OnTerminate();
}
void PA33X::OnSample(){
    SamplePressure();
}

const PressureSample PA33X::OnSamplePressure() {
    PressureSample sample;
    sample.pressure = 33;
    return sample;
}