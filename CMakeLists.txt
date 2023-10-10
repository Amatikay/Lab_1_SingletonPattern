cmake_minimum_required(VERSION 3.1)
project(Lab_1)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HEADER_FILES "include/*.h")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_library(Lab_1_lib INTERFACE)
target_sources(Lab_1_lib INTERFACE ${HEADER_FILES})
target_include_directories(Lab_1_lib INTERFACE include)

add_executable(Lab_1_run ${SOURCE_FILES})
target_link_libraries(Lab_1_run Lab_1_lib)

add_subdirectory(googletest)
file(GLOB_RECURSE TEST_FILES "test/*.cpp")
add_executable(Lab_1_test ${TEST_FILES})
target_link_libraries(Lab_1_test Lab_1_lib gtest gtest_main)