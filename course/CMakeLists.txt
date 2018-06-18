add_executable(test_start test_start.cpp)
target_link_libraries(test_start gtest_main)

add_test(NAME test_start COMMAND test_start)

add_subdirectory(leap_year)
add_subdirectory(stack)