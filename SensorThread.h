#include <thread>
#include <chrono>
#include <functional>
#include "Sensor.h"
#include <vector>
using namespace std;

 class SensorThread
 {
    private:
        thread t;
        bool running;

    public:
        void startThread(int ms, std::function<void()> callback_function);
        void startThread(int ms);
        void stopThread();
         };