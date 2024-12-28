#include "SettingsCSVReader.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>

std::shared_ptr<SettingsCSVReader> SettingsCSVReader::instance = nullptr;

SettingsCSVReader::SettingsCSVReader(const std::string& path) {
    assert(!path.empty());
    assert(path.find(".csv") != std::string::npos);

    file.open(path);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + path);
    }

    loadFile();
}

SettingsCSVReader::~SettingsCSVReader() {
    if (file.is_open()) {
        file.close();
    }
}

void SettingsCSVReader::loadFile() {
    std::string line;
    std::string currentSection;

    while (std::getline(file, line)) {
        line = trim(line);

        if (line.empty()) {
            continue;
        }

        if (line.find(':') == std::string::npos) {
            currentSection = trim(line);
            sections[currentSection];
        } else {
            size_t colonPos = line.find(':');
            std::string key = trim(line.substr(0, colonPos));
            std::string value = trim(line.substr(colonPos + 1));

            if (!currentSection.empty()) {
                sections[currentSection][key] = value;
            } else {
                throw std::runtime_error("Found key-value pair before a section header.");
            }
        }
    }

    file.clear();
    file.seekg(0, std::ios::beg);
}

std::string SettingsCSVReader::trim(const std::string& text) {
    std::string result = text;
    result.erase(0, result.find_first_not_of(" \t\r\n"));
    result.erase(result.find_last_not_of(" \t\r\n") + 1);
    return result;
}

std::string SettingsCSVReader::readSettings(const std::string& section, const std::string& key) {
    try {
        auto sectionIt = sections.find(section);
        if (sectionIt == sections.end()) {
            throw std::runtime_error("Section not found: " + section);
        }

        auto keyIt = sectionIt->second.find(key);
        if (keyIt == sectionIt->second.end()) {
            throw std::runtime_error("Key not found: " + key);
        }

        return keyIt->second;
    } catch (const std::exception& e) {
        throw std::runtime_error("Error while reading settings: " + std::string(e.what()));
    }
}

std::shared_ptr<SettingsCSVReader> SettingsCSVReader::getInstance(const std::string& path) {
    if (!instance) {
        instance = std::shared_ptr<SettingsCSVReader>(new SettingsCSVReader(path));
    }
    return instance;
}
