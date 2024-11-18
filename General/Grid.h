//
// Created by Piotrek on 29.10.2024.
//

#ifndef GRID_H
#define GRID_H

#include "Tile.h"
#include "Utilities/Renderer.h"
#include <vector>
#include "EnvironmentHandler.h"


class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<Tile>> tiles;

    /**
    * @brief Function that checks if the given coordinates are in bounds of the grid.
    * @param x X coordinate on grid.
    * @param y Y coordinate on grid.
    * @return True if the coordinates are in bounds, false otherwise.
    */
    bool isInBounds(int x, int y) const;
    void randomGrassGeneration();
    void perlinNoiseGrassGeneration();

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
    friend class EnvironmentHandler;
    int getWidth() const;
    int getHeight() const;
    /**
     * @brief Function that returns tile at the given coordinates.
     * @param x
     * @param y
     * @return Tile
     */
    Tile* getTile(int x, int y);
    /**
     * @brief Function that returns tile addresses in the radius around the given coordinates.
     *
     * Function uses the manhattan distance to determine if the tile is in the range.
     * @param centerX
     * @param centerY
     * @param range
     * @return vector of tile addresses in the range.
     */
    std::vector<Tile*>* getSurroundingTiles(int centerX, int centerY, int range);
    void clearGrid();
    void printGrid();
};



#endif //GRID_H
