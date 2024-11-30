#include "HerbivoreAnimal.h"
#include "Simulation/Resources/GrassResource.h"

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY) :
Animal(id, startX, startY,5, 50, 100, 5, 1, AnimalType::HERBIVORE, 10, 100, 100){}

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                                 int sightRange, int strength, int maxEatAmount, int health, int maxHealth) :
Animal(id, startX, startY, speed, currentEnergy, maxEnergy, sightRange, strength, AnimalType::HERBIVORE, maxEatAmount, health, maxHealth){}

Action* HerbivoreAnimal::chooseEatAction(Tile *currentTile) {
    std::vector<Resource*> resourcesOnTile = currentTile->getResourcesOnTile();
    for (auto resource : resourcesOnTile) {
        if (resource->getType() == GRASS) {
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

Action* HerbivoreAnimal::chooseDieAction() {
    int resourceAmount = maxHealth / 2 + currentEnergy / 2;
    if (this->health <= 0 || this->currentEnergy <= 0) {
        return new ActionDie(resourceAmount);
    }
    return nullptr;
}

Action* HerbivoreAnimal::chooseAction(std::vector<Tile*> &surroundingTiles){

    // Check if animal is dead
    Action* action = chooseDieAction();
    if (action != nullptr) {
        return action;
    }

    Tile* currentTile = nullptr;
    for (Tile* tile : surroundingTiles) {
        if (tile->getX() == this->getX() && tile->getY() == this->getY()) {
            currentTile = tile;
            break;
        }
    }

    // Check if animal doesn't float in the abyss
    if (currentTile != nullptr) {
        action = chooseEatAction(currentTile);
        if (action != nullptr){
            return action;
        }
    }

    if (currentEnergy < maxEnergy / 2) {
        action = chooseMoveActionToNearestTileWithFood(surroundingTiles);
        if (action != nullptr) {
            return action;
        }
    }

    // If no action was chosen, return move to the current position so basically do nothing
    return new ActionMove(this->getX(), this->getY());
}

HerbivoreAnimal::~HerbivoreAnimal() = default;