#ifndef ALTIMETER_SOURCE_H
#define ALTIMETER_SOURCE_H

#include <functional>
#include <vector>
#include <iostream>

using std::vector;

struct AltimeterSample {
public:
     double distance;
};

class AltimeterSource {
public:
    void RegisterAltimeterReceiver(std::function<void(const AltimeterSample)> callback_function);
    const AltimeterSample SampleAltimeter() const;

protected:
    virtual const AltimeterSample OnSampleAltimeter() const = 0;

private:
    void NotifySampleUpdate(const AltimeterSample& new_sample) const;
    vector<std::function<void(const AltimeterSample)>> callback_functions={};
};

#endif // ALTIMETER_SOURCE_H