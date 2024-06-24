#include "PressureSource.h"

void PressureSource::RegisterPressureReceiver(std::function<void(const PressureSample&)> callback_function){
    callback_functions.push_back(callback_function);
}

const PressureSample PressureSource:: SamplePressure() {
    PressureSample sample;
    sample = OnSamplePressure();
    NotifySampleUpdate(sample);
    return sample;
}

void PressureSource::NotifySampleUpdate(const PressureSample& new_sample) const{
    for(auto& callback : callback_functions){
        callback(new_sample);
    }
}