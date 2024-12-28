//
// Created by ddf on 28.10.2024.
//

#include <random>
#include <iostream>
#include "Utilities/FileHandling/SettingsCSVReader.h"
#include "Utilities/StatisticsManager.h"
#include "Grid.h"
#include "Simulation/Animals/HerbivoreAnimal.h"
#include "General/SimulationManager.h"
#include "Simulation/Resources/MeatResource.h"
#include "Simulation/Spawners/Spawner.h"
#include <memory>

#include "Simulation/Animals/CarnivoreAnimal.h"

int main() {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("Files/settings.csv");
    Grid* grid = new Grid();
    std::shared_ptr<StatisticsManager> stats = StatisticsManager::getInstance();

    Spawner spawner(grid, stats);
    spawner.populateGrid();

    SimulationManager manager(grid);
    manager.runSimulation();

    delete grid;

    return 0;
}
