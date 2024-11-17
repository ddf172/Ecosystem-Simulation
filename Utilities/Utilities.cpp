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
