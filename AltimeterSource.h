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
private:
    void NotifySampleUpdate(const AltimeterSample& new_sample) const;
    vector<std::function<void(const AltimeterSample)>> callback_functions={};

public:
    void RegisterAltimeterReceiver(std::function<void(const AltimeterSample&)> callback_function);
    const AltimeterSample SampleAltimeter();

protected:
    virtual const AltimeterSample OnSampleAltimeter() = 0;
};

#endif // ALTIMETER_SOURCE_H