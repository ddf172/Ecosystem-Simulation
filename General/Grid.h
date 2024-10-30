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
    int width;
    int height;
    std::vector<std::vector<Tile>> tiles;

    void RandomGrassGeneration();
    void PerlinNoiseGrassGeneration();

public:
    enum GenType {
        RANDOM,
        PERLIN
    };
    /**
    * Constructor, which initializes empty grid
    * @param width Width of the grid.
    * @param height Height of the grid
    */
    Grid(int width, int height, GenType genType);
    friend class Utilities::Renderer;
    std::vector<Tile> GetSurroundingTiles(int centerX, int centerY, int radius);
    int getWidth() const;
    int getHeight() const;
    void ClearGrid();
    void PrintGrid();
};



#endif //GRID_H
