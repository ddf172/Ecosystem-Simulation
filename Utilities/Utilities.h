//
// Created by jakub on 17.11.2024.
//

#ifndef ECOSYSTEM_SIMULATION_UTILITIES_H
#define ECOSYSTEM_SIMULATION_UTILITIES_H

#include <cmath>
#include <General/Tile.h>

class Tile;

bool canReach(int x1, int y1, int x2, int y2, int numberOfMoves);

bool canReach(const Tile& t1, const Tile& t2, int numberOfMoves);

int calculateDistance(int x1, int y1, int x2, int y2);

int calculateDistance(const Tile& t1, const Tile& t2);

#endif //ECOSYSTEM_SIMULATION_UTILITIES_H
