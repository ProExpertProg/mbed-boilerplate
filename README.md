# mbed-boilerplate
A repository with MbedOS boilerplate code using mbed-cmake as the build system, googletest for unit tests, and mbed-benchtest for Hardware-out-of-the-Loop (HOOTL) tests. It relies on CMake for building the code and supports various upload methods.

## Quick start
Simply clone this repository, delete any code you don't need, and start writing your code! (Definitely try building all targets after you delete things so you make sure you didn't miss anything).

## Overview
Today's embedded workflows require very rigorous and extensive testing at every level, from unit-testing at the lowest level to testing the whole application on hardware, as well as everything in between. These levels (as we see it) are as follows:

1. **Unit Testing**: Compiled for a desktop OS (x86), testing each unit of the program in isolation, with dependencies stubbed out. Each test will be its own target and included in the ctest target.
1. **Hardware-out-of-the-Loop (HOOTL) testing**: Compiled for a desktop OS (x86), this tests larger parts of the program without running on the hardware. It supports RTOS features so the concurency of the program can be tested. This can include multiple targets with various parts of the core program logic and can share some of the stubbing already in use by the unit-testing infrastructure.
1. **Hardware and hardware driver testing**: To validate the hardware be free of malfunction and to provide testing of drivers (and wrappers) on the same level as unit-testing of core-logic code of our application, we need certain smaller targets that only include those that we can then run on the hardware. We plan on adding support for Mbed's included testing capabilities (Greentea etc.).

## Directory structure
- `unit-tests` includes the unit tests with the accompanying infrastructure (googletest, mocks, stubs, etc.). It pulls the code under test from `firmware`.
- `hootl` includes the hootl tests and infrastructure (mbed-benchtest as well as additional stubs that simulate abstracted components).
- `firmware` includes the core application code, drivers/wrappers, hardware tests, and uses the mbed-cmake build system to build hardware targets (both tests and production applications). It also contans upload logic.

## Room for improvements

### Directory structure
Currently, the firmware directory is quite "beefy" and has quite a few responsibilities. What's more, both unit-test and hootl refer to core-logic code there, so that's the only part shared between all three. Perhaps, that part of the code could get a new top-level directory (and the wrappers, drivers, as well as hardware tests could be all left inside the firmware directory for a better separation of concerns. This could be especially helpful if there were multiple application targets in the repository (perhaps because a lot of the drivers and wrappers are shared).

### Using Mbed's own build system
In the future, we might shift to using Mbed's own CMake build system, as soon as their uploads methods, reliability, and flexibility exceed that of mbed-cmake. It can also be easily used with minor adjustments to only the `CMakeLists.txt` inside the `firmware` directory.

## Contributing
Help us with mbed-benchtest and/or create a PR to this repository. You can also let us know your problems/comments/thoughts by creating issues. More documentation is coming soon.
