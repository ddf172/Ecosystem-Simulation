#include "Application.h"
#include <iostream>

Application::Application() {
    reader = SettingsCSVReader::overrideInstance("Files/settings.csv");
    grid = new Grid();
    stats = StatisticsManager::getInstance();
    spawner = new Spawner(grid, stats);
    manager = new SimulationManager(grid);
}

Application::~Application() {
    delete grid;
    delete spawner;
    delete manager;
}

void Application::run() {
    spawner->populateGrid();
    manager->runSimulation();
}
