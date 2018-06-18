project(sc-cpp)

cmake_minimum_required(VERSION 3.5.1)

enable_testing()

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)

add_subdirectory(course)
add_subdirectory(hackathon)