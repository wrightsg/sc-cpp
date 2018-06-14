add_library(turtle INTERFACE)

target_include_directories(turtle INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(turtle INTERFACE gmock)

add_executable(test_turtle test_turtle.cpp)
target_link_libraries(test_turtle turtle gtest_main)

add_test(NAME test_turtle COMMAND test_turtle)