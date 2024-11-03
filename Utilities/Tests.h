//
// Created by Piotrek on 29.10.2024.
//

#include <General/Grid.h>

#ifndef TESTS_H
#define TESTS_H

void testGenerateRandomMapAndPrint(int width, int height) {
    Grid grid = Grid(width, height, Grid::GenType::RANDOM);
    grid.printGrid();
    grid.clearGrid();
}

#endif //TESTS_H
