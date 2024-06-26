// #include "Sensor.h"
// using namespace std;

// Sensor::Sensor(const std::string& sensor_name, int ms) : name(sensor_name), ms(ms){
//     sensor_thread_ = new SensorThread();
//     Sensor::OnInitialize();
// }

// Sensor::~Sensor() {
//     Sensor::OnTerminate();
// }

// void Sensor::OnInitialize() {
//     sensor_thread_->startThread(ms, [this](){
//         // Call the OnSample method
//         this->OnSample();
//     });
// }

// void Sensor::OnTerminate() {
//     sensor_thread_->stopThread();
// }

