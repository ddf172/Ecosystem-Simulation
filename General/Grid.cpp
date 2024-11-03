//
// Created by Piotrek on 29.10.2024.
//

#include "Grid.h"

#include <iostream>
#include <vector>
#include <random>
#include "Simulation/GrassResource.h"


Grid::Grid(int width, int height, GenType genType) {
    this->width = width;
    this->height = height;
    for (int i = 0; i < height; i++) {
        this->tiles.push_back(std::vector<Tile>());
        for (int j = 0; j < width; j++) {
            this->tiles[i].push_back(Tile(i, j));
        }
    }
    if (genType == RANDOM) {
        randomGrassGeneration();
    } else if (genType == PERLIN) {
        perlinNoiseGrassGeneration();
    }
}

int Grid::getWidth() const{
    return this->width;
}

int Grid::getHeight() const{
    return this->height;
}

bool Grid::isInBounds(int x, int y) const {
    return x >= 0 && x < this->width && y >= 0 && y < this->height;
}

std::vector<Tile> Grid::getSurroundingTiles(int centerX, int centerY, int range) {
    // Check if the input is valid
    if (range < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    if (!isInBounds(centerX, centerY)) {
        throw std::invalid_argument("Center is out of bounds");
    }

    std::vector<Tile> surroundingTiles;
    for (int i = std::max(centerX - range, 0); i <= std::min(centerX + range, this->getWidth() - 1); i++) {
        for (int j = std::max(centerY - range, 0); j <= std::min(centerY + range, this->getHeight() - 1); j++) {
            surroundingTiles.push_back(this->tiles[i][j]);
        }
    }
    return surroundingTiles;
}

void Grid::randomGrassGeneration() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution distribution(0.3);

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            int randNum = distribution(gen);
            if (randNum == 1) {
                Resource* newGrass = new GrassResource(30, 3);
                this->tiles[i][j].setResourceOnTile(newGrass);
            }
        }
    }
}

void Grid::perlinNoiseGrassGeneration() {

}


void Grid::printGrid() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            if (this->tiles[i][j].getResourceOnTile()->getType() == GRASS) {
                std::cout << "W";
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}

void Grid::clearGrid() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            delete this->tiles[i][j].getResourceOnTile();
        }
    }
}
