#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

extern "C" int mbed_start() {
    std::cout << "Hello, World!" << std::endl;
    ThisThread::sleep_for(1s);
    cout << "Done! Now ending" << endl;
    exit(0);
}
