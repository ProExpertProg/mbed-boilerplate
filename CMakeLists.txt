cmake_minimum_required(VERSION 3.16)

# circumvent the try_compile in the hardware target
project(mbed-boilerplate LANGUAGES NONE) # TODO project name

if (HARDWARE_TARGET)
    message(STATUS "Building firmware")
    add_subdirectory(firmware)
elseif (NOT HARDWARE_TARGET)
    message(STATUS "Building tests")
    enable_testing()
    add_subdirectory(unit-test)
    add_subdirectory(hootl)
endif ()