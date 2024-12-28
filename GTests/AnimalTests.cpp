#include <gtest/gtest.h>
#include "Simulation/Animals/Animal.h"
#include "Simulation/Animals/CarnivoreAnimal.h"
#include "Simulation/Animals/HerbivoreAnimal.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"

TEST(AnimalTest, InitializeAnimal) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Animal> animal = std::make_shared<HerbivoreAnimal>(42, 0, 0);

    EXPECT_EQ(animal->getId(), 42);
    EXPECT_EQ(animal->getX(), 0);
    EXPECT_EQ(animal->getY(), 0);
    SettingsCSVReader::releaseInstance();
}

TEST(AnimalTest, getAdvancedData) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Animal> animal = std::make_shared<HerbivoreAnimal>(42, 0, 0);

    EXPECT_EQ(animal->getId(), 42);
    EXPECT_EQ(animal->getX(), 0);
    EXPECT_EQ(animal->getY(), 0);
    EXPECT_EQ(animal->getSpeed(), 5);
    EXPECT_EQ(animal->getType(), AnimalType::HERBIVORE);
    EXPECT_EQ(animal->getHealth(), 100);
    EXPECT_EQ(animal->getMaxHealth(), 100);
    EXPECT_EQ(animal->getFoodTypes().size(), 1);
    SettingsCSVReader::releaseInstance();
}

TEST(AnimalTest, getAdvancedDataButCarnivore) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Animal> animal = std::make_shared<CarnivoreAnimal>(42, 0, 0);

    EXPECT_EQ(animal->getId(), 42);
    EXPECT_EQ(animal->getX(), 0);
    EXPECT_EQ(animal->getY(), 0);
    EXPECT_EQ(animal->getSpeed(), 5);
    EXPECT_EQ(animal->getType(), AnimalType::CARNIVORE);
    EXPECT_EQ(animal->getHealth(), 100);
    EXPECT_EQ(animal->getMaxHealth(), 100);
    EXPECT_EQ(animal->getFoodTypes().size(), 1);
    SettingsCSVReader::releaseInstance();
}
