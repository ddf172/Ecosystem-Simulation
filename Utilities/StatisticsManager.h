#ifndef STATISTICSMANAGER_H
#define STATISTICSMANAGER_H

#include <string>
#include <map>
#include <memory>

class StatisticsManager {
private:
    struct TurnStats {
        int carnivoreDeaths = 0;
        int herbivoreDeaths = 0;
        int omnivoreDeaths = 0;
        int carnivoresAlive = 0;
        int herbivoresAlive = 0;
        int omnivoresAlive = 0;
    };

    static std::shared_ptr<StatisticsManager> instance;
    std::map<int, TurnStats> turnStatistics;
    int currentTurn;
    std::string outputFilePath;

    StatisticsManager();

public:
    StatisticsManager(const StatisticsManager&) = delete;
    StatisticsManager& operator=(const StatisticsManager&) = delete;

    static std::shared_ptr<StatisticsManager> getInstance();

    void incrementTurn();
    void recordDeath(const std::string& type);
    void recordBirth(const std::string& type);
    void saveToFile() const;

    int getCurrentTurnDeaths(const std::string& type) const;
    int getAliveCount(const std::string& type) const;

    ~StatisticsManager() = default;
};

#endif
