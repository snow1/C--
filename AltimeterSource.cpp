#include "AltimeterSource.h"
#include <iostream>
#include <functional>
using namespace std;

void AltimeterSource::RegisterAltimeterReceiver(std::function<void(const AltimeterSample&)> callback_function){
    callback_functions.push_back(callback_function);
}

const AltimeterSample AltimeterSource::SampleAltimeter() {
    AltimeterSample sample = OnSampleAltimeter();
    NotifySampleUpdate(sample);
    return sample;
}

void AltimeterSource::NotifySampleUpdate(const AltimeterSample& new_sample) const{
    for(auto& callback : callback_functions){
        callback(new_sample);
    }
}