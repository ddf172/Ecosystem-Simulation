#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileManager::FileManager(const std::string& settingsFileName) : settingsFileName(settingsFileName) {
    readFile();
}

bool FileManager::readFile() {
    std::ifstream file(settingsFileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << settingsFileName << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key; std::string value;
        if (std::getline(iss, key, ':') && std::getline(iss, value)) {
            settings[key] = value;
        }
    }

    file.close();
    return true;
}

std::string FileManager::get(const std::string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return it->second;
    }
    return "";  // Return empty string if setting not found
}

int FileManager::getInt(const std::string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return std::stoi(it->second);
    }
    return 0;
}

float FileManager::getFloat(const std::string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
        return std::stof(it->second);
    }
    return 0.0;
}