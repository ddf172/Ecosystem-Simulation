project(GTests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(GTests_run
        GridTests.cpp
        TileTests.cpp
        MergingContainerTests.cpp
        SettingsCSVReaderTests.cpp
        AnimalTests.cpp
        ResourceTests.cpp
)

target_link_libraries(GTests_run Ecosystem_Simulation_lib)

target_link_libraries(GTests_run gtest gtest_main)

add_custom_command(
        TARGET GTests_run POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Copying from ${CMAKE_SOURCE_DIR}/GTests/TestSettings to ${CMAKE_BINARY_DIR}/GTests/TestSettings"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/GTests/TestSettings ${CMAKE_BINARY_DIR}/bin/GTests/TestSettings
)