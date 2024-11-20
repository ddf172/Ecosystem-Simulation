//
// Created by ddf on 28.10.2024.
//

#include <Utilities/Renderer.h>

#include "Grid.h"

int main() {
    Utilities::Renderer renderer = Utilities::Renderer();
    Grid grid(40, 20, Grid::RANDOM);
    renderer.renderGrid(grid);
    return 0;
}
