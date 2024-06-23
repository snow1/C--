#ifndef INERTIA_SOURCE_H
#define INERTIA_SOURCE_H

#include <functional>
#include <string>
struct InertiaSample {
    // Add members as required
};

class InertiaSource {
public:
    void RegisterInertiaReceiver(std::function<void(const InertiaSample&)> callback_function);
    const InertiaSample SampleInertia();

protected:
    virtual const double OnSampleInertia() = 0;
private:
    void NotifySampleUpdate(const InertiaSample& new_sample) const;
};

#endif // INERTIA_SOURCE_H
