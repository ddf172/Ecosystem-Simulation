#include <gtest/gtest.h>
#include "Simulation/Animals/Animal.h"
#include "Simulation/Animals/CarnivoreAnimal.h"
#include "Simulation/Animals/HerbivoreAnimal.h"
#include "Simulation/Actions/Action.h"
#include "Simulation/Actions/ActionDie.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"
#include "Simulation/Resources/ResourceTypeEnum.h"

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

TEST(AnimalTest, playDead) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Animal> animal = std::make_shared<CarnivoreAnimal>(42, 0, 0);
    EXPECT_EQ(animal->getHealth(), 100);
    animal->executeAction(std::make_shared<ActionDie>(0));
    EXPECT_EQ(animal->getHealth(), 0);
    SettingsCSVReader::releaseInstance();
}

TEST(AnimalTest, eat) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Animal> animal = std::make_shared<HerbivoreAnimal>(42, 0, 0);
    EXPECT_EQ(animal->getCurrentEnergy(), 50);
    animal->executeAction(std::make_shared<ActionEat>(30,GRASS)); //eating takes 10 energy here
    EXPECT_EQ(animal->getCurrentEnergy(), 70);
    SettingsCSVReader::releaseInstance();
}

TEST(AnimalTest, movement) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Animal> animal = std::make_shared<HerbivoreAnimal>(42, 10, 10);
    animal->executeAction(std::make_shared<ActionMove>(30,30));
    EXPECT_EQ(animal->getX(), 30);
    EXPECT_EQ(animal->getY(), 30);
    SettingsCSVReader::releaseInstance();
}

TEST(AnimalTest, checkAbstraction) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Animal> animal = std::make_shared<HerbivoreAnimal>(42, 10, 10);
    animal->executeAction(std::make_shared<ActionMove>(30,30));
    EXPECT_EQ(animal->getX(), 30);
    EXPECT_EQ(animal->getY(), 30);
    animal = std::make_shared<CarnivoreAnimal>(42, 10, 10);
    EXPECT_EQ(animal->getHealth(), 100);
    animal->executeAction(std::make_shared<ActionDie>(0));
    EXPECT_EQ(animal->getHealth(), 0);
    SettingsCSVReader::releaseInstance();
}
