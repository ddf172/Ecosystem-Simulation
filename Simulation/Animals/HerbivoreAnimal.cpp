#include "HerbivoreAnimal.h"
#include "Simulation/GrassResource.h"

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength)
        : Animal(id, startX, startY, speed, maxEnergy, sightRange, strength, AnimalType::HERBIVORE) {
}

Action* HerbivoreAnimal::chooseMoveToNearestTileWithFood(std::vector<Tile*>* surroundingTiles) {
    std::pair<Tile*, int> closestTileWithFood = {nullptr, 100000};
    for (Tile* tile : *surroundingTiles) {
        Resource* resource = tile->getResourceOnTile();
        if (resource != nullptr && resource->getType() == ResourceType::GRASS) {
            int distance = calculateDistance(this->getX(), this->getY(), tile->getX(), tile->getY());
            if (canReach(this->getX(), this->getY(), tile->getX(), tile->getY(), this->speed)
                && distance < closestTileWithFood.second) {
                closestTileWithFood = {tile, distance};
            }
        }

    }
    if (closestTileWithFood.first != nullptr) {
        return new ActionMove(closestTileWithFood.first->getX(), closestTileWithFood.first->getY());
    }
    return nullptr;
}

Action* HerbivoreAnimal::chooseAction(std::vector<Tile*>* surroundingTiles) {
    // Test version of chooseAction
    // Herbivore will move to the nearest tile with food if currentEnergy is less than 50% of maxEnergy
    // find tile on which animal stays
    Tile* currentTile = nullptr;
    for (Tile* tile : *surroundingTiles) {
        if (tile->getX() == this->getX() && tile->getY() == this->getY()) {
            currentTile = tile;
            break;
        }
    }

    if (currentEnergy < maxEnergy / 2) {
        Action* action = chooseMoveToNearestTileWithFood(surroundingTiles);
        if (action != nullptr) {
            return action;
        }
    }

    return new ActionMove(this->getX(), this->getY());
}