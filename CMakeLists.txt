cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

#include all necessary directories
include_directories(include
        googletest-master/googletest/include
        googletest-master/googlemock/include)


add_subdirectory(googletest-master)
link_libraries(gmock)

add_executable(median2vector_run src/main.cpp )
add_executable(median2vector_test test/median_test.cpp )
add_executable(palindrome_test  test/palindrome_test.cpp)
add_executable(find_substring_test  test/find_substring_test.cpp )

