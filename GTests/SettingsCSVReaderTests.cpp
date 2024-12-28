#include <gtest/gtest.h>
#include "Utilities/FileHandling/SettingsCSVReader.h"

TEST(SettingsCSVReaderTest, InitializeInstance) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    ASSERT_NE(reader, nullptr);
    EXPECT_EQ(reader->readSettings("General", "key1"), "value1");
    EXPECT_EQ(reader->readSettings("Network", "keyA"), "valueA");
    SettingsCSVReader::releaseInstance();
}

TEST(SettingsCSVReaderTest, ReleaseInstance) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    SettingsCSVReader::releaseInstance();
    reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest2.csv");
    EXPECT_EQ(reader->readSettings("General", "key1"), "value1wrong");
    EXPECT_EQ(reader->readSettings("Network", "keyA"), "valueAwrong");
    SettingsCSVReader::releaseInstance();
}

TEST(SettingsCSVReaderTest, DontOverrideInstance) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest.csv");
    reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest2.csv");
    EXPECT_EQ(reader->readSettings("General", "key1"), "value1");
    EXPECT_EQ(reader->readSettings("Network", "keyA"), "valueA");
    SettingsCSVReader::releaseInstance();
}

TEST(SettingsCSVReaderTest, OverrideInstance) {
    std::shared_ptr<SettingsCSVReader> reader = SettingsCSVReader::getInstance("GTests/TestSettings/SettingsTest2.csv");
    reader = SettingsCSVReader::overrideInstance("GTests/TestSettings/SettingsTest.csv");
    EXPECT_EQ(reader->readSettings("General", "key1"), "value1");
    EXPECT_EQ(reader->readSettings("Network", "keyA"), "valueA");
    SettingsCSVReader::releaseInstance();
}
