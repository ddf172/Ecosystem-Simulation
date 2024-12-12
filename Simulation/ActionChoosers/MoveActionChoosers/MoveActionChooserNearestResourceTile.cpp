//
// Created by ddf on 11.12.2024.
//

#include "MoveActionChooserNearestResourceTile.h"

MoveActionChooserNearestResourceTile::MoveActionChooserNearestResourceTile(std::vector<Tile*>& tilesWithResources) : tilesWithResources(tilesWithResources) {}

Action* MoveActionChooserNearestResourceTile::chooseAction(Animal* animal) {
    if (tilesWithResources.empty()) {
        return nullptr;
    }

    Tile* nearestTile = *std::min_element(tilesWithResources.begin(), tilesWithResources.end(), [animal](Tile* a, Tile* b) {
        if (a->getX() == animal->getX() && a->getY() == animal->getY()) {
            return false;
        }
        int distanceA = calculateDistance(animal->getX(), animal->getY(), a->getX(), a->getY());
        int distanceB = calculateDistance(animal->getX(), animal->getY(), b->getX(), b->getY());
        return distanceA < distanceB;
    });

    return new ActionMove(nearestTile->getX(), nearestTile->getY());
}