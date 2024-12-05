//
// Created by jakub on 17.11.2024.
//
#include "Utilities.h"

bool canReach(int x1, int y1, int x2, int y2, int numberOfMoves) {
    return abs(x1 - x2) + abs(y1 - y2) <= numberOfMoves;
}

bool canReach(const Tile& t1, const Tile& t2, int numberOfMoves) {
    return canReach(t1.getX(), t1.getY(), t2.getX(), t2.getY(), numberOfMoves);
}

int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int calculateDistance(const Tile& t1, const Tile& t2) {
    return calculateDistance(t1.getX(), t1.getY(), t2.getX(), t2.getY());
}

std::vector<Tile *> getTilesWithResources(const std::vector<Tile *> &tiles, const std::vector<ResourceType> &foodTypes) {
    std::vector<Tile *> result;
    for (Tile *tile : tiles) {
        std::vector<Resource*>* tileResources = tile->getResourcesOnTile();
        for (Resource *resource : *tileResources) {
            if (std::find(foodTypes.begin(), foodTypes.end(), resource->getType()) != foodTypes.end()) {
                result.push_back(tile);
                break;
            }
        }
    }
    return result;
}

Tile* getCurrentPositionTile(std::vector<Tile*> &surroundingTiles, int x, int y) {
    for (Tile* tile : surroundingTiles) {
        if (tile->getX() == x && tile->getY() == y) {
            return tile;
        }
    }
    return nullptr;
}