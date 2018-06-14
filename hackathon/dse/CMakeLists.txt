add_library(dse
    system.cpp
)
target_include_directories(dse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(entity_mock INTERFACE)
target_include_directories(entity_mock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entity_mock INTERFACE gmock)

add_executable(test_entity test_entity.cpp)
target_link_libraries(test_entity gtest_main)
add_test(NAME test_entity COMMAND test_entity)

add_executable(test_system test_system.cpp)
target_link_libraries(test_system entity_mock dse gtest_main)
add_test(NAME test_system COMMAND test_system)