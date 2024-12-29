//
// Created by Piotrek on 29.12.2024.
//

#include "Spawner.h"
#include <random>

Spawner::Spawner(Grid* grid, std::shared_ptr<StatisticsManager> stats)
: grid(grid), stats(std::move(stats)) {
    this->carnivorePercent = std::stof(SettingsCSVReader::getInstance()->readSettings("Spawner","herbivoresPercent"));
    this->herbivorePercent = std::stof(SettingsCSVReader::getInstance()->readSettings("Spawner","carnivoresPercent"));
}

float Spawner::getRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0, 1.0);
    return dist(gen);
}

void Spawner::spawnCarnivore(int i, int j){
    stats->recordBirth("herbivore");
    auto herbivore = std::make_shared<HerbivoreAnimal>(0, j, i);
    grid->getTile(j, i)->addAnimalOnTile(herbivore);
}

void Spawner::spawnHerbivore(int i, int j){
    stats->recordBirth("carnivore");
    auto carnivore = std::make_shared<CarnivoreAnimal>(0, j, i);
    grid->getTile(j, i)->addAnimalOnTile(carnivore);
}

void Spawner::populateGrid() {
    for (int i = 0; i < grid->getHeight(); i++) {
        for (int j = 0; j < grid->getWidth(); j++) {
            if(getRandomNumber()<herbivorePercent){
                spawnHerbivore(i, j);
            }
            if(getRandomNumber()<carnivorePercent){
                spawnCarnivore(i, j);
            }
        }
    }
}
