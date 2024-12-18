cmake_minimum_required(VERSION 3.22)
project(Ecosystem_Simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(.)

add_executable(Ecosystem_Simulation
        General/Grid.cpp
        General/Grid.h
        General/Tile.h
        General/Tile.cpp
        General/SimulationManager.h
        General/main.cpp
        General/SimulationManager.cpp
        Simulation/Animals/Animal.h
        Simulation/Animals/Animal.cpp
        Simulation/Resources/GrassResource.h
        Simulation/Resources/Resource.h
        Simulation/Resources/Resource.cpp
        Simulation/Resources/GrassResource.cpp
        Simulation/Resources/ResourceTypeEnum.h
        Simulation/Animals/HerbivoreAnimal.cpp
        Simulation/Animals/HerbivoreAnimal.h
        Utilities/Utilities.h
        Utilities/Utilities.cpp
        Simulation/Actions/Action.h
        Simulation/Actions/Action.cpp
        Simulation/Actions/ActionTypeEnum.h
        Simulation/Actions/ActionMove.cpp
        Simulation/Actions/ActionMove.h
        Simulation/Actions/ActionEat.cpp
        Simulation/Actions/ActionEat.h
        Simulation/Animals/AnimalTypeEnum.h
        Simulation/Actions/ActionNone.cpp
        Simulation/Actions/ActionNone.h
        Simulation/Actions/ActionDie.cpp
        Simulation/Actions/ActionDie.h
        Simulation/Actions/ActionDie.cpp
        General/Rendering/Renderer.cpp
        General/Rendering/Renderer.h
        General/Rendering/GraphicAnimal.cpp
        General/Rendering/GraphicAnimal.h
        General/Rendering/GraphicTile.cpp
        General/Rendering/GraphicTile.h
        Utilities/MergingContainer.h
        Simulation/Brains/Brain.cpp
        Simulation/Brains/Brain.h
        Simulation/ActionChoosers/IActionChooser.h
        Simulation/ActionChoosers/EatActionChoosers/EatActionChooserDefault.cpp
        Simulation/ActionChoosers/EatActionChoosers/EatActionChooserDefault.h
        Simulation/ActionChoosers/MoveActionChoosers/MoveActionChooserNearestResourceTile.cpp
        Simulation/ActionChoosers/MoveActionChoosers/MoveActionChooserNearestResourceTile.h
        Simulation/ActionChoosers/DieActionChoosers/DieActionChooserDefault.cpp
        Simulation/ActionChoosers/DieActionChoosers/DieActionChooserDefault.h
        Simulation/Resources/MeatResource.cpp
        Simulation/Resources/MeatResource.h
        Simulation/Actions/ActionReproduce.cpp
        Simulation/Actions/ActionReproduce.h
        Simulation/ActionChoosers/ReproduceActionChoosers/ReproduceActionChooserSoloDefault.cpp
        Simulation/ActionChoosers/ReproduceActionChoosers/ReproduceActionChooserSoloDefault.h
        Simulation/Actions/ActionAttack.cpp
        Simulation/Actions/ActionAttack.h
        Simulation/ActionChoosers/AttackActionChooser/AttackActionChooserDefault.cpp
        Simulation/ActionChoosers/AttackActionChooser/AttackActionChooserDefault.h
)

target_link_libraries(Ecosystem_Simulation PRIVATE sfml-graphics sfml-system sfml-window)
target_compile_features(Ecosystem_Simulation PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
            TARGET Ecosystem_Simulation
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Ecosystem_Simulation>
            VERBATIM)
endif()