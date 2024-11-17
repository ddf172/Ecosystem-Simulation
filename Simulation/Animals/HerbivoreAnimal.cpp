#include "HerbivoreAnimal.h"
#include "Simulation/GrassResource.h"
#include <typeinfo>

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength)
        : Animal(id, startX, startY, speed, maxEnergy, sightRange, strength, AnimalType::HERBIVORE) {
}

void HerbivoreAnimal::chooseAction(std::vector<Tile*> surroundingTiles) {
    // Test version of chooseAction
    // Herbivore will move to the nearest tile with food
    std::pair<Tile*, int> closestTileWithFood = {nullptr, 100000};
    for (Tile* tile : surroundingTiles) {
        Resource* resource = tile->getResourceOnTile();
        if (resource != nullptr && typeid(*resource) == typeid(GrassResource)) {
            int distance = calculateDistance(this->getX(), this->getY(), tile->getX(), tile->getY());
            if (canReach(this->getX(), this->getY(), tile->getX(), tile->getY(), this->speed)
                && distance < closestTileWithFood.second) {
                closestTileWithFood = {tile, distance};
            }
        }

    }
    if (closestTileWithFood.first != nullptr) {
        move(closestTileWithFood.first->getX(), closestTileWithFood.first->getY());
    }
}