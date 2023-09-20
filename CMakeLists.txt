cmake_minimum_required(VERSION 3.25)
project(Lab_1)

set(CMAKE_CXX_STANDARD 17)

add_library(Lab_1_lib INTERFACE)
target_sources(Lab_1_lib INTERFACE
        include/StackTemplate.h
        include/Exception.h
        include/Person.h
        include/PersonKeeper.h)
target_include_directories(Lab_1_lib INTERFACE include)

add_executable( Lab_1_run
        src/main.cpp)
target_link_libraries(Lab_1_run Lab_1_lib)

add_subdirectory(googletest)
add_executable(Lab_1_test
        test/test.cpp)
target_link_libraries(Lab_1_test
        Lab_1_lib
        gtest
        gtest_main)
