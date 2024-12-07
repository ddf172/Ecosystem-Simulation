#include "HerbivoreAnimal.h"

#include <iostream>

#include "Simulation/Resources/GrassResource.h"

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY) :
Animal(id, startX, startY, 5, 50, 100, 5, 1, AnimalType::HERBIVORE, 10, 100, 100){}

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                                 int sightRange, int strength, int maxEatAmount, int health, int maxHealth) :
Animal(id, startX, startY, speed, currentEnergy, maxEnergy, sightRange, strength, AnimalType::HERBIVORE, maxEatAmount, health, maxHealth){}

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

    tilesWithFood = getTilesWithResources(surroundingTiles, foodTypes);
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
    Action* action = chooseEatAction(getCurrentPositionTile(surroundingTiles, this->getX(), this->getY()));
    if (action != nullptr) return action;

    if (currentEnergy < maxEnergy / 2) {
        action = chooseMoveActionToNearestTileWithFood(surroundingTiles);
    }
    if (action != nullptr) return action;

    // If no action was chosen, return move to the current position so basically do nothing
    return new ActionMove(this->getX(), this->getY());
}

HerbivoreAnimal::~HerbivoreAnimal() = default;