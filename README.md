# mbed-boilerplate
A repository with MbedOS boilerplate code using [mbed-cmake](https://github.com/USCRPL/mbed-cmake) as the build system, GoogleTest for unit tests, and [mbed-benchtest](https://github.com/USCRPL/mbed-benchtest) for Hardware-out-of-the-Loop (HOOTL) tests. It relies on CMake for building the code and supports various upload methods.

## Quick start
1. Clone this repository (recursively)
1. Delete any code you don't need
1. Adjust your project (recommended spots are marked with TODO, and have a look at [CMake Profiles](#cmake-profiles))
1. Configure mbed-cmake for your target processor. More instructions [here](https://github.com/USCRPL/mbed-cmake/wiki/Project-Configuration)
1. Start writing your code!
   
Definitely try building all targets after you delete things so you make sure you didn't miss anything.

## Overview
Today's embedded workflows require very rigorous and extensive testing at every level, from unit-testing at the lowest level to testing the whole application on hardware, as well as everything in between. These levels (as we see it) are as follows:

1. **Unit Testing**: Compiled for a desktop OS (x86), testing each unit of the program in isolation, with dependencies stubbed out. Each test will be its own target and included in the ctest target.
1. **Hardware-out-of-the-Loop (HOOTL) testing**: Compiled for a desktop OS (x86), this tests larger parts of the program without running on the hardware. It supports RTOS features so the concurency of the program can be tested. This can include multiple targets with various parts of the core program logic and can share some of the stubbing already in use by the unit-testing infrastructure.
1. **Hardware and hardware driver testing**: To validate the hardware be free of malfunction and to provide testing of drivers (and wrappers) on the same level as unit-testing of core-logic code of our application, we need certain smaller targets that only include those that we can then run on the hardware. We plan on adding support for Mbed's included testing capabilities (Greentea etc.).

## Directory structure
- `unit-test` contains the unit tests with the accompanying infrastructure (GoogleTest, mocks, stubs, etc.). It pulls the code under test from `firmware`.
- `hootl` contains the hootl tests and infrastructure (mbed-benchtest as well as additional stubs that simulate abstracted components).
- `firmware` contains drivers/wrappers, hardware tests, and uses the mbed-cmake build system to build hardware targets (both tests and production applications). It also contans upload logic.
- `application` contains the core application code, which is shared between all three of the above.

## CMake profiles 
This project is using CMake and hence supports CLion out-of-the-box (in fact, CLion is the authors' editor of choice). However, any editor can be used for this project.

Because building the code for the hardware and building the desktop tests requires two completely different toolchains, we need two separate build profiles. The code in place will distinguish between them using the `HARDWARE_TARGET` flag that needs to be passed to CMake. This scales with any build configuration types and further options and is handled gracefully by CLion. It also works well with a manual CMake build. 

## Room for improvements

### Using Mbed's own build system
In the future, we might shift to using Mbed's own CMake build system, as soon as their uploads methods, reliability, and flexibility exceed that of mbed-cmake. It can also be easily used with minor adjustments to only the `CMakeLists.txt` inside the `firmware` directory.

## Contributing
Help us with [mbed-benchtest](https://github.com/USCRPL/mbed-benchtest) and/or create a PR to this repository. You can also let us know your problems/comments/thoughts by creating issues. More documentation is coming soon.
