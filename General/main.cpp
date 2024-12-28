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
#include <memory>

#include "Simulation/Animals/CarnivoreAnimal.h"

// Created purely to test rendering
int getRandomNumber() {
    std::random_device rd; // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister random number engine
    std::uniform_int_distribution<int> dist(0, 16); // Range: 0 to 8
    return dist(gen);
}

// Created for testing
void spawnHerbivoreAnimals(Grid* grid) {
    std::shared_ptr<StatisticsManager> stats = StatisticsManager::getInstance();
    for(int i = 0; i < grid->getHeight(); i++) {
        for(int j = 0; j < grid->getWidth(); j++) {
            int n = getRandomNumber();
            switch (n) {
                case 0:
                    stats->recordBirth("herbivore");
                    grid->getTile(j, i)->addAnimalOnTile(std::make_shared<HerbivoreAnimal>(0, j, i));
                    break;
                case 1:
                    stats->recordBirth("carnivore");
                    grid->getTile(j, i)->addAnimalOnTile(std::make_shared<CarnivoreAnimal>(0, j, i));
                break;
            }
        }
    }
}

int main() {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("Files/settings.csv");
    Grid* grid = new Grid();
    spawnHerbivoreAnimals(grid); // Random herbivoreAnimal spawn for testing
    SimulationManager manager(grid, true, 1000);
    manager.runSimulation();

    delete grid;

    return 0;
}