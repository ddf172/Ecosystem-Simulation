//
// Created by Piotrek on 29.10.2024.
//

#include "Grid.h"

#include <vector>

Grid::Grid(int width, int height) {
    for (int i = 0; i < height; i++) {
        this->tiles.push_back(std::vector<Tile>());
        for (int j = 0; j < width; j++) {
            this->tiles[i].push_back(Tile(i, j, nullptr));
        }
    }
}
