#include <gtest/gtest.h>
#include "Simulation/Resources/GrassResource.h"
#include "Simulation/Resources/MeatResource.h"
#include "Simulation/Resources/Resource.h"
#include "Simulation/Resources/ResourceTypeEnum.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"

TEST(ResourceTest, InitializeGrass) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<GrassResource> grass = std::make_shared<GrassResource>(42);
    EXPECT_EQ(grass->getAmount(), 42);
    EXPECT_EQ(grass->getEnergyValue(), 1);
    SettingsCSVReader::releaseInstance();
}

TEST(ResourceTest, InitializeMeat) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<MeatResource> meat = std::make_shared<MeatResource>(42);
    EXPECT_EQ(meat->getAmount(), 42);
    EXPECT_EQ(meat->getEnergyValue(), 1);
    SettingsCSVReader::releaseInstance();
}

TEST(ResourceTest, CheckAbstraction) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<Resource> abstractResource = std::make_shared<MeatResource>(42);
    EXPECT_EQ(abstractResource->getAmount(), 42);
    EXPECT_EQ(abstractResource->getEnergyValue(), 1);
    abstractResource = std::make_shared<GrassResource>(50);
    EXPECT_EQ(abstractResource->getAmount(), 50);
    EXPECT_EQ(abstractResource->getEnergyValue(), 1);
    SettingsCSVReader::releaseInstance();
}

TEST(ResourceTest, CheckGrowing) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    std::shared_ptr<GrassResource> grass = std::make_shared<GrassResource>(42);
    EXPECT_EQ(grass->getCurrentRegrowCooldown(), 3);
    grass->setCurrentRegrowCooldown(grass->getCurrentRegrowCooldown()-3);
    EXPECT_EQ(grass->getCurrentRegrowCooldown(), 0);
    SettingsCSVReader::releaseInstance();
}