add_library(dse
    system.cpp
)

add_executable(test_entity test_entity.cpp)
target_link_libraries(test_entity gtest_main)
add_test(NAME test_entity COMMAND test_entity)

add_executable(test_system test_system.cpp)
target_link_libraries(test_system dse gmock gtest_main)
add_test(NAME test_system COMMAND test_system)