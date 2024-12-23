#include "SettingsCSVReader.h"

SettingsCSVReader::SettingsCSVReader(const std::string& path) {
    assert(!path.empty());
    assert(path.find(".csv") != std::string::npos);

    file.open(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }

    mapSections();
}

SettingsCSVReader::~SettingsCSVReader() {
    if (file.is_open()) {
        file.close();
    }
}

void SettingsCSVReader::mapSections() {
    std::string line;
    while (std::getline(file, line)) {
        if (line.find(':') == std::string::npos && !line.empty()) {
            line = trim(line);
            if (line.empty()) {
                continue;
            }
            sectionPositions[line] = file.tellg();
        }
    }

    file.clear();
    file.seekg(0);
}

std::streampos SettingsCSVReader::findSection(const std::string& section) {
    auto it = sectionPositions.find(section);
    if (it == sectionPositions.end()) {
        throw std::runtime_error("Section not found: " + section);
    }
    return it->second;
}

std::string SettingsCSVReader::trim(const std::string& text) {
    std::string result = text;
    result.erase(0, result.find_first_not_of(" \t\r\n"));
    result.erase(result.find_last_not_of(" \t\r\n") + 1);
    return result;
}

std::string SettingsCSVReader::readSettings(const std::string& section, const std::string& key) {
    assert(file.is_open());
    assert(!section.empty());
    assert(!key.empty());


    try {
        std::streampos sectionPos = findSection(section);
        file.seekg(sectionPos);

        std::string line;
        while (std::getline(file, line) && !line.empty() && line.find(':') != std::string::npos) {
            size_t colonPos = line.find(':');
            std::string currentKey = line.substr(0, colonPos);

            currentKey = trim(currentKey);

            if (currentKey == key) {
                std::string value = line.substr(colonPos + 1);
                value = trim(value);
                return value;
            }
        }

        file.clear();
        file.seekg(0);
        throw std::runtime_error("Key not found: " + key);
    } catch (const std::exception& e) {
        file.clear();
        file.seekg(0);
        throw std::runtime_error(std::string("Error while reading settings: ") + e.what());
    }
}