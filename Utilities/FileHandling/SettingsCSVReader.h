//
// Created by jakub on 23.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_SETTINGSCSVREADER_H
#define ECOSYSTEM_SIMULATION_SETTINGSCSVREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include <stdexcept>

class SettingsCSVReader {
private:
    std::ifstream file;
    std::map<std::string, std::streampos> sectionPositions;

    void mapSections();
    std::streampos findSection(const std::string& section);
    static std::string trim(const std::string& text);

public:
    explicit SettingsCSVReader(const std::string& path);
    ~SettingsCSVReader();

    SettingsCSVReader(const SettingsCSVReader&) = delete;
    SettingsCSVReader& operator=(const SettingsCSVReader&) = delete;

    std::string readSettings(const std::string& section, const std::string& key);
};



#endif //ECOSYSTEM_SIMULATION_SETTINGSCSVREADER_H
