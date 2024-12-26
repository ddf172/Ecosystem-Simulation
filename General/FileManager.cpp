#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

std::shared_ptr<FileManager> FileManager::instance = nullptr;

FileManager::FileManager(){
    FileManager::readFile("Files/settings.txt");
}

std::shared_ptr<FileManager> FileManager::getInstance() {
    if (!instance) {
        instance = std::make_shared<FileManager>();
    }

    if (instance == nullptr) {
        throw std::invalid_argument("FileManager instance is null");
    }
    return instance;
}

const bool FileManager::readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << fileName << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, ':') && std::getline(iss, value)) {
            data[key] = value;
        }
    }

    file.close();
    return true;
}

std::string FileManager::get(const std::string& key) const {
    auto it = data.find(key);
    if (it != data.end()) {
        return it->second;
    }
    return "";
}

int FileManager::getInt(const std::string& key) const {
    auto it = data.find(key);
    if (it != data.end()) {
        return std::stoi(it->second);
    }
    return 0;
}

float FileManager::getFloat(const std::string& key) const {
    auto it = data.find(key);
    if (it != data.end()) {
        return std::stof(it->second);
    }
    return 0.0;
}

bool FileManager::getBool(const std::string& key) const {
    auto it = data.find(key);
    if (it != data.end()) {
        if(it->second == "true")
        {
            return true;
        }
    }
    return false;
}