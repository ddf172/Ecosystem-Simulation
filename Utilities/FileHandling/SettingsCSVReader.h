#ifndef ECOSYSTEM_SIMULATION_SETTINGSCSVREADER_H
#define ECOSYSTEM_SIMULATION_SETTINGSCSVREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include <stdexcept>
#include <memory>

class SettingsCSVReader : public std::enable_shared_from_this<SettingsCSVReader> {
protected:
    explicit SettingsCSVReader(const std::string& path);

private:
    std::ifstream file;
    std::map<std::string, std::map<std::string, std::string>> sections;
    static std::shared_ptr<SettingsCSVReader> instance;

    SettingsCSVReader(const SettingsCSVReader&) = delete;
    SettingsCSVReader& operator=(const SettingsCSVReader&) = delete;

    void loadFile();
    static std::string trim(const std::string& text);

public:
    static std::shared_ptr<SettingsCSVReader> getInstance(const std::string& path = "Files/settings.csv");

    ~SettingsCSVReader();

    std::string readSettings(const std::string& section, const std::string& key);
};

#endif //ECOSYSTEM_SIMULATION_SETTINGSCSVREADER_H