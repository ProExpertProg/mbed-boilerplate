#include <iostream>
#include <chrono>
#include <rtos.h>

using namespace std;
using namespace std::chrono_literals;

extern "C" int mbed_start() {
    cout << "Hello, World!" << endl;
    ThisThread::sleep_for(1s);
    cout << "Done! Now ending" << endl;
    exit(0);
}
