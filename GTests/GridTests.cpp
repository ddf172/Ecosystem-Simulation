#include <gtest/gtest.h>
#include "General/SimulationEngine/Grid.h"

TEST(GridTest, ConstructorValidDimensions) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest1");
    EXPECT_EQ(grid->getWidth(), 5);
    EXPECT_EQ(grid->getHeight(), 4);
}

TEST(GridTest, ConstructorZeroDimensions) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest2");
    EXPECT_EQ(grid->getWidth(), 0);
    EXPECT_EQ(grid->getHeight(), 0);
}

TEST(GridTest, GetTileValidCoordinates) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest3");
    auto tile = grid->getTile(1, 1);
    EXPECT_NE(tile, nullptr);
}

TEST(GridTest, GetTileInvalidCoordinates) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest4");
    EXPECT_THROW(grid->getTile(-1, -1), std::invalid_argument);
    EXPECT_THROW(grid->getTile(3, 3), std::invalid_argument);
}

TEST(GridTest, GetSurroundingTiles) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest5");
    auto surroundingTiles = grid->getSurroundingTiles(2, 2, 1);
    EXPECT_EQ(surroundingTiles.size(), 9);
}

TEST(GridTest, RandomGeneration) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest6");
    bool hasNonNullTiles = false;

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (grid->getTile(x, y) != nullptr) {
                hasNonNullTiles = true;
                break;
            }
        }
    }
    EXPECT_TRUE(hasNonNullTiles);
}

TEST(GridTest, GetSurroundingTilesBoundary) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest7");
    auto surroundingTiles = grid->getSurroundingTiles(1, 1, 5);
    EXPECT_LE(surroundingTiles.size(), 9);
}

TEST(GridTest, LargeGridCreation) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest8");
    EXPECT_EQ(grid->getWidth(), 100);
    EXPECT_EQ(grid->getHeight(), 100);

    EXPECT_NE(grid->getTile(0, 0), nullptr);
    EXPECT_NE(grid->getTile(99, 99), nullptr);
}

TEST(GridTest, RandomGrassGeneration) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/GridTests.csv");
    Grid* grid = new Grid("GridTest9");
    int grassCount = 0;
    const int size = 1000;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (grid->getTile(x, y)->getResourcesOnTile()->size() > 0) {
                grassCount++;
            }
        }
    }

    EXPECT_GE(grassCount, 290000);
    EXPECT_LE(grassCount, 310000);
}
