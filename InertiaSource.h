#ifndef INERTIA_SOURCE_H
#define INERTIA_SOURCE_H

#include <functional>
#include <iostream>
#include <vector>

using std::vector;

struct InertiaSample {
    double x;
};

class InertiaSource {
private:
    void NotifySampleUpdate(const InertiaSample& new_sample) const;
    vector<std::function<void(const InertiaSample)>> callback_functions = {};

public:
    void RegisterInertiaReceiver(std::function<void(const InertiaSample&)> callback_function);
    const InertiaSample SampleInertia(); 

protected:
    virtual const InertiaSample OnSampleInertia() = 0;



};

#endif // INERTIA_SOURCE_H
