//
// Created by ddf on 11.12.2024.
//

#include <cassert>
#include "MoveActionChooserNearestResourceTile.h"

MoveActionChooserNearestResourceTile::MoveActionChooserNearestResourceTile(std::vector<Tile*>& tilesWithResources) : tilesWithResources(tilesWithResources) {}

MoveActionChooserNearestResourceTile::MoveActionChooserNearestResourceTile() : tilesWithResources(std::vector<Tile*>()) {}

Action* MoveActionChooserNearestResourceTile::chooseAction(Animal* animal) {
    assert (animal != nullptr);

    if (tilesWithResources.empty()) {
        return nullptr;
    }

    tilesWithResources.erase(std::remove_if(tilesWithResources.begin(), tilesWithResources.end(), [animal](Tile* tile) {
        return tile->getX() == animal->getX() && tile->getY() == animal->getY();
    }), tilesWithResources.end());

    Tile* nearestTile = *std::min_element(tilesWithResources.begin(), tilesWithResources.end(), [animal](Tile* a, Tile* b) {
        int distanceA = calculateDistance(animal->getX(), animal->getY(), a->getX(), a->getY());
        int distanceB = calculateDistance(animal->getX(), animal->getY(), b->getX(), b->getY());
        return distanceA < distanceB;
    });

    return new ActionMove(nearestTile->getX(), nearestTile->getY());
}

void MoveActionChooserNearestResourceTile::setTilesWithResources(std::vector<Tile*>& newTilesWithResources) {
    tilesWithResources = newTilesWithResources;
}

MoveActionChooserNearestResourceTile::~MoveActionChooserNearestResourceTile() = default;