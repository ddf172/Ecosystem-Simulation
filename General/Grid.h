//
// Created by Piotrek on 29.10.2024.
//

#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include "Utilities/Renderer.h"
#include <vector>


class Grid {
private:
    std::vector<std::vector<Tile>> tiles;

public:
    /**
    * Constructor, which initializes empty grid
    * @param width Width of the grid.
    * @param height Height of the grid
    */
    Grid(int width, int height);
    friend class Utilities::Renderer;
    std::vector<Tile> GetSurroundingTiles(int centerX, int centerY, int radius);
};



#endif //GRID_H
