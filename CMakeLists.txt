project(sc-cpp)

cmake_minimum_required(VERSION 3.5.1)

enable_testing()

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)

add_subdirectory(dse)
add_subdirectory(hello_world)
add_subdirectory(turtle)
