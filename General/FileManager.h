#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <unordered_map>
#include <map>
#include <memory>

//To use:
//  copy this line to access SettingsManager
//      std::shared_ptr<FileManager> SettingsManager = FileManager::getInstance();
//  access data in settings.txt using:
//      string s = SettingsManager->get("s");
//      int width = SettingsManager->getInt("width");
//      float prob = SettingsManager->getFloat("grassProbability");
//      bool isRandom = SettingsManager->getBool("GenTypeRandom");

class FileManager {
public:
    FileManager();

    static std::shared_ptr<FileManager> getInstance();
    const bool readFile(const std::string& fileName);
    std::string get(const std::string& key) const;
    int getInt(const std::string& key) const;
    float getFloat(const std::string& key) const;
    bool getBool(const std::string& key) const;

    ~FileManager() = default;

private:
    static std::shared_ptr<FileManager> instance;
    std::string fileName;
    std::map<std::string, std::string> data;
};

#endif