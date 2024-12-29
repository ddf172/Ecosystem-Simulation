#include "General/SimulationEngine/Grid.h"
#include <iostream>
#include <vector>
#include <random>
#include "Simulation/Resources/GrassResource.h"


Grid::Grid(std::string settingsSection) {
    
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance();
    this->width = std::stoi(reader->readSettings(settingsSection, "width"));
    this->height = std::stoi(reader->readSettings(settingsSection, "height"));
    this->grassProbability = std::stof(reader->readSettings(settingsSection, "grassProbability"));
    for (int i = 0; i < height; i++) {
        this->tiles.push_back(std::vector<std::shared_ptr<Tile>>());
        for (int j = 0; j < width; j++) {
            this->tiles[i].push_back(std::make_shared<Tile>(j, i));
        }
    }
    if (reader->readSettings(settingsSection,"GenTypeRandom") == "true") {
        randomGrassGeneration();
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

std::vector<std::shared_ptr<Tile>> Grid::getSurroundingTiles(int centerX, int centerY, int range) {
    // Check if the input is valid
    if (range < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    if (!isInBounds(centerX, centerY)) {
        throw std::invalid_argument("Center is out of bounds");
    }

    auto surroundingTiles = std::vector<std::shared_ptr<Tile>>();
    for (int i = std::max(centerX - range, 0); i <= std::min(centerX + range, this->getWidth() - 1); i++) {
        for (int j = std::max(centerY - range, 0); j <= std::min(centerY + range, this->getHeight() - 1); j++) {
            surroundingTiles.push_back(this->tiles[j][i]);
        }
    }
    return surroundingTiles;
}

std::shared_ptr<Tile> Grid::getTile(int x, int y) {
    if (!isInBounds(x, y)) {
        throw std::invalid_argument("Coordinates out of bounds");
    }
    return this->tiles[y][x];
}

void Grid::randomGrassGeneration() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution distribution(this->grassProbability);

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            int randNum = distribution(gen);
            if (randNum == 1) {
                this->tiles[i][j]->addResourceOnTile(std::make_shared<GrassResource>(100));
            }
        }
    }
}