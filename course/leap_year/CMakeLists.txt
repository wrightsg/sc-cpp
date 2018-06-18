add_executable(test_year test_year.cpp)
target_link_libraries(test_year gtest_main)

add_test(NAME test_year COMMAND test_year)