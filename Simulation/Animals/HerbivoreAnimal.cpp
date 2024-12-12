#include "HerbivoreAnimal.h"

#include <iostream>

#include "Simulation/Resources/GrassResource.h"

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY) :
Animal(id, startX, startY, 5, 50, 100, 5, 1, AnimalType::HERBIVORE,
       25, 100, 100, {ResourceType::GRASS}){
    initializeBrain();
}

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                                 int sightRange, int strength, int maxEatAmount, int health, int maxHealth) :
Animal(id, startX, startY, speed, currentEnergy, maxEnergy, sightRange, strength, AnimalType::HERBIVORE, maxEatAmount, health, maxHealth, {ResourceType::GRASS}){
    initializeBrain();
}

void HerbivoreAnimal::initializeBrain() {
    brain.addActionChooser(new DieActionChooserDefault());
    brain.addActionChooser(new EatActionChooserDefault());
    brain.addActionChooser(new MoveActionChooserNearestResourceTile());
}

Action* HerbivoreAnimal::chooseAction(std::vector<Tile*> &surroundingTiles){
    Tile *currentTile = getCurrentPositionTile(surroundingTiles, getX(), getY());
    std::vector<Tile*> tilesWithResources = getTilesWithResources(surroundingTiles, {GRASS}, 20);
    for (auto &actionChooser : brain.getActionChoosers()) {
        if (auto *eatActionChooser = dynamic_cast<EatActionChooserDefault*>(actionChooser.get())) {
            eatActionChooser->setCurrentTile(currentTile);
        }
        if (auto *moveActionChooser = dynamic_cast<MoveActionChooserNearestResourceTile*>(actionChooser.get())) {
            moveActionChooser->setTilesWithResources(tilesWithResources);
        }
    }
    return brain.chooseAction();
}

HerbivoreAnimal::~HerbivoreAnimal() = default;