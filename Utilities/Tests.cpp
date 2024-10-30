//
// Created by Piotrek on 29.10.2024.
//

#include <General/Grid.h>

namespace Utilities {
    void TestGenerateRandomMapAndPrint(int width, int height) {
        Grid grid = Grid(width, height, Grid::GenType::RANDOM);
        grid.PrintGrid();
        grid.ClearGrid();
    }
}
