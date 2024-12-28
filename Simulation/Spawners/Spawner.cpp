#include "Spawner.h"
#include <random>
#include "Simulation/Animals/HerbivoreAnimal.h"
#include "Simulation/Animals/CarnivoreAnimal.h"

Spawner::Spawner(Grid* grid, std::shared_ptr<StatisticsManager> stats)
    : grid(grid), stats(std::move(stats)) {}

int Spawner::getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void Spawner::populateGrid() {
    for (int i = 0; i < grid->getHeight(); i++) {
        for (int j = 0; j < grid->getWidth(); j++) {
            int n = getRandomNumber(0, 16);
            switch (n) {
                case 0: {
                    stats->recordBirth("herbivore");
                    auto herbivore = std::make_shared<HerbivoreAnimal>(0, j, i);
                    grid->getTile(j, i)->addAnimalOnTile(herbivore);
                    break;
                }
                case 1: {
                    stats->recordBirth("carnivore");
                    auto carnivore = std::make_shared<CarnivoreAnimal>(0, j, i);
                    grid->getTile(j, i)->addAnimalOnTile(carnivore);
                    break;
                }
                default:
                    break;
            }
        }
    }
}
