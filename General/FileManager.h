#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <unordered_map>

class FileManager {
public:
    FileManager(const std::string& settingsFileName);
    bool readFile();
    std::string get(const std::string &key) const;
    int getInt(const std::string &key) const;
    float getFloat(const std::string &key) const;

private:
    std::string settingsFileName;
    std::unordered_map<std::string, std::string> settings;

};

#endif