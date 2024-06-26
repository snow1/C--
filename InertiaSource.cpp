#include "InertiaSource.h"

using namespace std;


void InertiaSource::RegisterInertiaReceiver(std::function<void(const InertiaSample&)> callback_function){
    callback_functions.push_back(callback_function);
}

const InertiaSample InertiaSource:: SampleInertia() {
    struct InertiaSample sample = OnSampleInertia();
    NotifySampleUpdate(sample);
    return sample;
}

void InertiaSource::NotifySampleUpdate(const InertiaSample& new_sample) const{
    for(auto& callback : callback_functions){
        callback(new_sample);
    }
}