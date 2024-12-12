#include "HerbivoreAnimal.h"

#include <iostream>

#include "Simulation/Resources/GrassResource.h"

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY) :
Animal(id, startX, startY, 5, 50, 100, 5, 1, AnimalType::HERBIVORE,
       25, 100, 100, {ResourceType::GRASS}){}

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                                 int sightRange, int strength, int maxEatAmount, int health, int maxHealth) :
Animal(id, startX, startY, speed, currentEnergy, maxEnergy, sightRange, strength, AnimalType::HERBIVORE, maxEatAmount, health, maxHealth, {ResourceType::GRASS}){}

Action* HerbivoreAnimal::chooseEatAction(Tile *currentTile) {
    std::vector<Resource*>* resourcesOnTile = currentTile->getResourcesOnTile();
    for (auto resource : *resourcesOnTile) {
        if (resource->getType() == GRASS) {
            if (resource->getAmount() < 20) {
                continue;
            }
            int amountToEat = calculateAmountToEat(*resource);
            return new ActionEat(amountToEat, ResourceType::GRASS);
        }
    }
    return nullptr;
}

Action* HerbivoreAnimal::chooseMoveActionToNearestTileWithFood(std::vector<Tile*> &surroundingTiles) {
    std::vector<Tile*> tilesWithFood;
    std::vector<ResourceType> foodTypes = {GRASS};

    tilesWithFood = getTilesWithResources(surroundingTiles, foodTypes, 20);
    if (tilesWithFood.empty()) {
        return nullptr;
    }

    Tile* nearestTile = *std::min_element(tilesWithFood.begin(), tilesWithFood.end(), [this](Tile* a, Tile* b) {
        int distanceA = calculateDistance(this->getX(), this->getY(), a->getX(), a->getY());
        int distanceB = calculateDistance(this->getX(), this->getY(), b->getX(), b->getY());
        return distanceA < distanceB;
    });

    return new ActionMove(nearestTile->getX(), nearestTile->getY());

}

Action* HerbivoreAnimal::chooseAction(std::vector<Tile*> &surroundingTiles){
    Tile *currentTile = getCurrentPositionTile(surroundingTiles, getX(), getY());
    Brain brain(this);
    brain.addActionChooser(new DieActionChooserDefault());
    brain.addActionChooser(new EatActionChooserDefault(currentTile));
    brain.addActionChooser(new MoveActionChooserNearestResourceTile(surroundingTiles));
    return brain.chooseAction();
}

HerbivoreAnimal::~HerbivoreAnimal() = default;