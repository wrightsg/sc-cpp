project(sc-cpp)

cmake_minimum_required(VERSION 3.5.1)

enable_testing()

add_subdirectory(lib)

add_executable(hello_world hello_world.cpp)
add_executable(test_hello_world test_hello_world.cpp)
target_link_libraries(test_hello_world gtest_main)

add_test(NAME test_hello_world COMMAND test_hello_world)
