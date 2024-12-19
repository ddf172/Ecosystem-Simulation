//
// Created by Piotr on 19.12.2024.
//

#include <gtest/gtest.h>
#include "General/Grid.h"

TEST(GridTest, ConstructorValidDimensions) {
    Grid grid(5, 4, Grid::GenType::NONE);
    EXPECT_EQ(grid.getWidth(), 5);
    EXPECT_EQ(grid.getHeight(), 4);
}

TEST(GridTest, ConstructorZeroDimensions) {
    Grid grid(0, 0, Grid::GenType::NONE);
    EXPECT_EQ(grid.getWidth(), 0);
    EXPECT_EQ(grid.getHeight(), 0);
}

TEST(GridTest, GetTileValidCoordinates) {
    Grid grid(3, 3, Grid::GenType::NONE);
    auto tile = grid.getTile(1, 1);
    EXPECT_NE(tile, nullptr);
}

TEST(GridTest, GetTileInvalidCoordinates) {
    Grid grid(3, 3, Grid::GenType::NONE);
    EXPECT_THROW(grid.getTile(-1, -1), std::invalid_argument);

    EXPECT_THROW(grid.getTile(3, 3), std::invalid_argument);
}

TEST(GridTest, GetSurroundingTiles) {
    Grid grid(5, 5, Grid::GenType::NONE);

    auto surroundingTiles = grid.getSurroundingTiles(2, 2, 1);
    EXPECT_EQ(surroundingTiles.size(), 9);

    surroundingTiles = grid.getSurroundingTiles(0, 0, 1);
    EXPECT_EQ(surroundingTiles.size(), 4);

    surroundingTiles = grid.getSurroundingTiles(0, 2, 2);
    EXPECT_GT(surroundingTiles.size(), 0);
}

TEST(GridTest, RandomGeneration) {
    Grid grid(4, 4, Grid::GenType::RANDOM);
    bool hasNonNullTiles = false;

    for(int x = 0; x < 4; x++) {
        for(int y = 0; y < 4; y++) {
            if(grid.getTile(x, y) != nullptr) {
                hasNonNullTiles = true;
                break;
            }
        }
    }
    EXPECT_TRUE(hasNonNullTiles);
}

TEST(GridTest, GetSurroundingTilesBoundary) {
    Grid grid(3, 3, Grid::GenType::NONE);

    auto surroundingTiles = grid.getSurroundingTiles(1, 1, 5);
    EXPECT_LE(surroundingTiles.size(), 9);

    surroundingTiles = grid.getSurroundingTiles(1, 1, 0);
    EXPECT_EQ(surroundingTiles.size(), 1);
}

TEST(GridTest, LargeGridCreation) {
    const int largeSize = 100;
    Grid grid(largeSize, largeSize, Grid::GenType::NONE);
    EXPECT_EQ(grid.getWidth(), largeSize);
    EXPECT_EQ(grid.getHeight(), largeSize);

    EXPECT_NE(grid.getTile(0, 0), nullptr);
    EXPECT_NE(grid.getTile(largeSize-1, largeSize-1), nullptr);
}

TEST(GridTest, RandomGrassGeneration) {
    const int size = 1000;
    Grid grid(size, size, Grid::GenType::RANDOM, 0.3);
    int grassCount = 0;
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++){
            if(grid.getTile(x, y)->getResourcesOnTile()->size() > 0) {
                grassCount++;
            }
        }
    }

    EXPECT_GE(grassCount, 290000);
    EXPECT_LE(grassCount, 310000);
}