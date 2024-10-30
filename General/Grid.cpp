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
            this->tiles[i].push_back(Tile(i, j, nullptr));
        }
    }
    if (genType == RANDOM) {
        RandomGrassGeneration();
    } else if (genType == PERLIN) {
        PerlinNoiseGrassGeneration();
    }
}

int Grid::getWidth() const{
    return this->width;
}

int Grid::getHeight() const{
    return this->height;
}

void Grid::RandomGrassGeneration() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution distribution(0.3);

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            int randNum = distribution(gen);
            if (randNum == 1) {
                Resource* newGrass = new GrassResource(30, 3);
                tiles[i][j].SetResourceOnTile(newGrass);
            }
        }
    }
}

void Grid::PerlinNoiseGrassGeneration() {

}


void Grid::PrintGrid() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            if (tiles[i][j].getResourceOnTile()->GetType() == GRASS) {
                std::cout << "W";
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}

void Grid::ClearGrid() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            delete tiles[i][j].getResourceOnTile();
        }
    }
}


