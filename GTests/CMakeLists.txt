project(GTests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(GTests_run
        GridTests.cpp
        TileTests.cpp
        AnimalBehaviourTests.cpp
        MergingContainerTests.cpp
        SettingsCSVReaderTests.cpp
        AnimalTests.cpp
)

target_link_libraries(GTests_run Ecosystem_Simulation_lib)

target_link_libraries(GTests_run gtest gtest_main)