#include "StatisticsManager.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::shared_ptr<StatisticsManager> StatisticsManager::instance = nullptr;

StatisticsManager::StatisticsManager()
    : currentTurn(0), outputFilePath("Files/statistics.csv") {}

std::shared_ptr<StatisticsManager> StatisticsManager::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<StatisticsManager>(new StatisticsManager());
    }
    return instance;
}

void StatisticsManager::incrementTurn() {
    currentTurn++;
    if (turnStatistics.find(currentTurn) == turnStatistics.end()) {
        turnStatistics[currentTurn] = TurnStats();
        turnStatistics[currentTurn].carnivoresAlive= turnStatistics[currentTurn-1].carnivoresAlive;
        turnStatistics[currentTurn].omnivoresAlive= turnStatistics[currentTurn-1].omnivoresAlive;
        turnStatistics[currentTurn].herbivoresAlive= turnStatistics[currentTurn-1].herbivoresAlive;
    }
}

void StatisticsManager::recordDeath(const std::string& type) {
    if (type == "carnivore") {
        turnStatistics[currentTurn].carnivoreDeaths++;
        turnStatistics[currentTurn].carnivoresAlive--;
    } else if (type == "herbivore") {
        turnStatistics[currentTurn].herbivoreDeaths++;
        turnStatistics[currentTurn].herbivoresAlive--;
    } else if (type == "omnivore") {
        turnStatistics[currentTurn].omnivoreDeaths++;
        turnStatistics[currentTurn].omnivoresAlive--;
    }
}

void StatisticsManager::recordBirth(const std::string& type) {
    if (type == "carnivore") {
        turnStatistics[currentTurn].carnivoresAlive++;
    } else if (type == "herbivore") {
        turnStatistics[currentTurn].herbivoresAlive++;
    } else if (type == "omnivore") {
        turnStatistics[currentTurn].omnivoresAlive++;
    }
}

void StatisticsManager::saveToFile() const {
    std::ofstream file(outputFilePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + outputFilePath);
    }

    // Write CSV headers
    file << "Turn,CarnivoreDeaths,HerbivoreDeaths,OmnivoreDeaths,CarnivoresAlive,HerbivoresAlive,OmnivoresAlive\n";

    for (const auto& [turn, stats] : turnStatistics) {
        file << turn << ","
             << stats.carnivoreDeaths << ","
             << stats.herbivoreDeaths << ","
             << stats.omnivoreDeaths << ","
             << stats.carnivoresAlive << ","
             << stats.herbivoresAlive << ","
             << stats.omnivoresAlive << "\n";
    }

    std::cout << "Statistics saved to " << outputFilePath << std::endl;
}

int StatisticsManager::getCurrentTurnDeaths(const std::string& type) const {
    if (type == "carnivore") return turnStatistics.at(currentTurn).carnivoreDeaths;
    if (type == "herbivore") return turnStatistics.at(currentTurn).herbivoreDeaths;
    if (type == "omnivore") return turnStatistics.at(currentTurn).omnivoreDeaths;
    return 0;
}

int StatisticsManager::getAliveCount(const std::string& type) const {
    if (type == "carnivore") return turnStatistics.at(currentTurn).carnivoresAlive;
    if (type == "herbivore") return turnStatistics.at(currentTurn).herbivoresAlive;
    if (type == "omnivore") return turnStatistics.at(currentTurn).omnivoresAlive;
    return 0;
}
