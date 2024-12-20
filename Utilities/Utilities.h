//
// Created by jakub on 17.11.2024.
//

#ifndef ECOSYSTEM_SIMULATION_UTILITIES_H
#define ECOSYSTEM_SIMULATION_UTILITIES_H

#include <cmath>
#include <General/Tile.h>
#include <vector>
#include <algorithm>
#include <memory>

class Tile;

bool canReach(int x1, int y1, int x2, int y2, int numberOfMoves);

bool canReach(const std::shared_ptr<Tile>& t1, const std::shared_ptr<Tile>& t2, int numberOfMoves);

int calculateDistance(int x1, int y1, int x2, int y2);

int calculateDistance(const std::shared_ptr<Tile>& t1, const std::shared_ptr<Tile>& t2);

std::vector<std::shared_ptr<Tile>> getTilesWithResources(const std::vector<std::shared_ptr<Tile>> &tiles, const std::vector<ResourceType> &foodTypes, int threshold = 20);

std::shared_ptr<Tile> getCurrentPositionTile(std::vector<std::shared_ptr<Tile>> &surroundingTiles, int x, int y);

#endif //ECOSYSTEM_SIMULATION_UTILITIES_H
