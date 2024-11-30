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
    // Find the closest tile with food
    std::pair<Tile*, int> closestTileWithFood = {nullptr, 100000};

    for (Tile* tile : surroundingTiles) {
        std::vector<Resource*> resourcesOnTile = tile->getResourcesOnTile();

        // Go through all resources on tile, if GRASS is found then calculate distance and break loop
        for (auto resource : resourcesOnTile) {
            if (resource->getType() == GRASS) {
                int distance = calculateDistance(this->getX(), this->getY(), tile->getX(), tile->getY());

                // If the animal can reach the tile and the tile is closer than the previous closest tile
                if (canReach(this->getX(), this->getY(), tile->getX(), tile->getY(), this->getSpeed())
                    && distance < closestTileWithFood.second){
                    closestTileWithFood = {tile, distance};
                }
                break;
            }
        }

    }
    if (closestTileWithFood.first != nullptr) {
        return new ActionMove(closestTileWithFood.first->getX(), closestTileWithFood.first->getY());
    }
    return nullptr;
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