cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

#include all necessary directories
include_directories(include
        googletest-master/googletest/include
        googletest-master/googlemock/include)

set(SOURCE_FILES
        src/main.cpp)

set(TEST_SOURCES
        test/main_test.cpp)

add_subdirectory(googletest-master)
link_libraries(gmock)

add_executable(median2vector_run ${SOURCE_FILES} )

add_executable(median2vector_test ${TEST_SOURCES} )

