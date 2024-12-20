//
// Created by jakub on 17.11.2024.
//
#include "Utilities.h"

bool canReach(int x1, int y1, int x2, int y2, int numberOfMoves) {
    return abs(x1 - x2) + abs(y1 - y2) <= numberOfMoves;
}

bool canReach(const std::shared_ptr<Tile>& t1, const std::shared_ptr<Tile>& t2, int numberOfMoves) {
    return canReach(t1->getX(), t1->getY(), t2->getX(), t2->getY(), numberOfMoves);
}

int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int calculateDistance(const std::shared_ptr<Tile>& t1, const std::shared_ptr<Tile>& t2) {
    return calculateDistance(t1->getX(), t1->getY(), t2->getX(), t2->getY());
}

std::vector<std::shared_ptr<Tile>> getTilesWithResources(const std::vector<std::shared_ptr<Tile>> &tiles, const std::vector<ResourceType> &foodTypes, int threshold) {
    std::vector<std::shared_ptr<Tile>> result;
    for (const auto& tile : tiles) {
        std::vector<std::shared_ptr<Resource>>* tileResources = tile->getResourcesOnTile();
        for (std::shared_ptr<Resource> resource : *tileResources) {
            if (std::find(foodTypes.begin(), foodTypes.end(), resource->getType()) != foodTypes.end()) {
                if (resource->getAmount() > threshold) {
                    result.push_back(tile);
                    break;
                }
            }
        }
    }
    return result;
}

std::shared_ptr<Tile> getCurrentPositionTile(std::vector<std::shared_ptr<Tile>> &surroundingTiles, int x, int y) {
    for (const auto& tile : surroundingTiles) {
        if (tile->getX() == x && tile->getY() == y) {
            return tile;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Tile>> getAnimalTargetTiles(const std::vector<std::shared_ptr<Tile>> &tiles, std::vector<AnimalType> targetTypes, const std::shared_ptr<Animal>& currentAnimal) {
    std::vector<std::shared_ptr<Tile>> result;
    for (const auto& tile : tiles) {
        std::vector<std::shared_ptr<Animal>>* animalsOnTile = tile->getAnimalsOnTile();
        for (std::shared_ptr<Animal> animal : *animalsOnTile) {
            if (std::find(targetTypes.begin(), targetTypes.end(), animal->getType()) != targetTypes.end() && animal != currentAnimal) {
                result.push_back(tile);
                break;
            }
        }
    }
    return result;
}