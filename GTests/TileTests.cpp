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

TEST(TileTest, TileAddingAnimals) {
    Tile tile = Tile(1, 1);
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 0);
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(1, 1, 1));
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 1);
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(2, 1, 1));
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(3, 1, 1));
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(4, 1, 1));
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 4);
}

TEST(TileTest, TileRemovingAnimals) {
    Tile tile = Tile(1, 1);
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 0);
    std::shared_ptr<Animal> firstAnimal = std::make_shared<HerbivoreAnimal>(1, 1, 1);
    tile.addAnimalOnTile(firstAnimal);
    tile.addAnimalOnTile(std::make_shared<HerbivoreAnimal>(2, 1, 1));
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 2);
    tile.removeAnimalOnTile(firstAnimal);
    EXPECT_EQ(tile.getAnimalsOnTile()->size(), 1);
    EXPECT_EQ(tile.getAnimalsOnTile()->at(0)->getId(), 2);
}

TEST(TileTest, TileAddingResources) {
    Tile tile = Tile(1, 1);

    EXPECT_EQ(tile.getResourcesOnTile()->size(), 0);

    std::shared_ptr<Resource> firstResource = std::make_shared<Resource>(GRASS, 0, 0);
    tile.addResourceOnTile(firstResource);
    EXPECT_EQ(tile.getResourcesOnTile()->size(), 1);

    tile.addResourceOnTile(std::make_shared<Resource>(GRASS, 0, 0));
    tile.addResourceOnTile(std::make_shared<Resource>(GRASS, 0, 0));
    tile.addResourceOnTile(std::make_shared<Resource>(GRASS, 0, 0));

    EXPECT_EQ(tile.getResourcesOnTile()->size(), 1);

    std::shared_ptr<Resource> differentResource = std::make_shared<Resource>(MEAT, 10, 10);
    tile.addResourceOnTile(differentResource);
    EXPECT_EQ(tile.getResourcesOnTile()->size(), 2);

    auto resources = tile.getResourcesOnTile();
    EXPECT_NE(std::find(resources->begin(), resources->end(), firstResource), resources->end());
}