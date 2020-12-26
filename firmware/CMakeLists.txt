cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

# load project upload methods (must be before mbed-cmake is loaded)
# -------------------------------------------------------------
include(cmake/UploadMethodConfig.cmake)

# load compilers and flags
# -------------------------------------------------------------
set(MBED_TOOLCHAIN_NAME "GCC_ARM")
include(lib/mbed-cmake/mbed-cmake.cmake)

project(firmware LANGUAGES NONE)

# recurse to subdirectories
# -------------------------------------------------------------

add_subdirectory(hardware-test)


# we need to switch out the wrappers in hootl, so the src folder needs to be in the include path (so we can replace it directly)
# all files that include wrappers also cannot use relative paths
include_directories(src)

add_mbed_executable(application src/main.cpp)

# ADD MORE EXECUTABLES HERE

# build report
# -------------------------------------------------------------

mbed_cmake_print_build_report()
