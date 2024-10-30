//
// Created by Piotrek on 29.10.2024.
//

#include <General/Grid.h>

#ifndef TESTS_H
#define TESTS_H

void TestGenerateRandomMapAndPrint(int width, int height) {
    Grid grid = Grid(width, height, Grid::GenType::RANDOM);
    grid.PrintGrid();
    grid.ClearGrid();
}

#endif //TESTS_H
