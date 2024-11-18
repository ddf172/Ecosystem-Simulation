//
// Created by Piotrek on 03.11.2024.
//

#include "EnvironmentHandler.h"

EnvironmentHandler::EnvironmentHandler(Grid* grid) {
    this->grid = grid;
}


std::vector<Tile*>* EnvironmentHandler::getSurroundingTiles(int centerX, int centerY, int range){
    return this->grid->getSurroundingTiles(centerX, centerY, range);
}