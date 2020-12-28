project(unit-tests LANGUAGES CXX)

add_subdirectory(lib/googletest EXCLUDE_FROM_ALL) # gmock built by default
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

include(UnitTest.cmake)
include_directories(../firmware/src)
add_unit_test(example tests/ExampleTest.cpp)

# ADD MORE TESTS HERE