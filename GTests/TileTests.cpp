//
// Created by Piotr on 19.12.2024.
//
#include <gtest/gtest.h>
#include "General/Tile.h"
#include "Simulation/Animals/HerbivoreAnimal.h"

TEST(TileTest, TileCreationTest) {
    Tile* tile = new Tile(1, 1);
    EXPECT_EQ(tile->getX(), 1);
    EXPECT_EQ(tile->getX(), 1);
    EXPECT_NE(tile, nullptr);
    delete tile;
}

TEST(TileTest, TileAnimals) {
    Tile tile = Tile(1, 1);
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 0);
    std::shared_ptr<Animal> firstAnimal = std::make_shared<HerbivoreAnimal>(1, 1, 1);
    tile.addAnimalOnTile(firstAnimal);
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 1);
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(1, 1, 1));
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(1, 1, 1));
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(1, 1, 1));
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 4);
    tile.removeAnimalOnTile(firstAnimal);
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 3);
}

