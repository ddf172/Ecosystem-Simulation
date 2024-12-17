//
// Created by ddf on 11.12.2024.
//

#include <cassert>
#include "MoveActionChooserNearestResourceTile.h"

MoveActionChooserNearestResourceTile::MoveActionChooserNearestResourceTile(std::vector<std::shared_ptr<Tile>>& tilesWithResources) : tilesWithResources(tilesWithResources) {}

MoveActionChooserNearestResourceTile::MoveActionChooserNearestResourceTile() : tilesWithResources(std::vector<std::shared_ptr<Tile>>()) {}

std::shared_ptr<Action> MoveActionChooserNearestResourceTile::chooseAction(Animal* animal) {;
    assert(animal != nullptr);

    if (tilesWithResources.empty()) {
        return nullptr;
    }

    tilesWithResources.erase(std::remove_if(tilesWithResources.begin(), tilesWithResources.end(), [animal](const std::shared_ptr<Tile>& tile) {
        return tile->getX() == animal->getX() && tile->getY() == animal->getY();
    }), tilesWithResources.end());

    std::shared_ptr<Tile> nearestTile = *std::min_element(tilesWithResources.begin(), tilesWithResources.end(), [animal](const std::shared_ptr<Tile>& a, const std::shared_ptr<Tile>& b) {
        int distanceA = calculateDistance(animal->getX(), animal->getY(), a->getX(), a->getY());
        int distanceB = calculateDistance(animal->getX(), animal->getY(), b->getX(), b->getY());
        return distanceA < distanceB;
    });

    return std::make_shared<ActionMove>(nearestTile->getX(), nearestTile->getY());
}

void MoveActionChooserNearestResourceTile::setTilesWithResources(std::vector<std::shared_ptr<Tile>>& newTilesWithResources) {
    tilesWithResources = newTilesWithResources;
}

MoveActionChooserNearestResourceTile::~MoveActionChooserNearestResourceTile() = default;