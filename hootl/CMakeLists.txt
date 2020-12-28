project(hootl LANGUAGES CXX)

# Here, files are structured in 3 groups (core, fake wrappers, and test files).
# TODO you can use whatever structure fits you best

# core application files
set(CORE_SRC ) # add application files
set(CORE_INCLUDE ../application/src)

# fake wrappers
set(WRAPPERS_SRC ) # add fake wrappers
set(WRAPPERS_INCLUDE src)

# TODO use a library or at them to hootl targets directly
# add_library(core_and_wrappers ${CORE_SRC} ${WRAPPERS_SRC})
# target_link_libraries(core_and_wrappers mbed_platform)
# target_include_directories(core_and_wrappers PUBLIC ${CORE_INCLUDE} ${WRAPPERS_INCLUDE})

# The backbone of hootl
add_subdirectory(lib/mbed-benchtest EXCLUDE_FROM_ALL)

add_executable(hootl main.cpp)
add_test(hootl hootl)

# mbed_platform is the mbed-benchtest target we want to link to
target_link_libraries(hootl mbed_platform) # TODO link core_and_wrappers

# ADD MORE HOOTL TARGETS, PERHAPS WITH A SUBSET OF CORE FILES AND WRAPPERS