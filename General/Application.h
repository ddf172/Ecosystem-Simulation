#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "General/SimulationEngine/Grid.h"
#include "General/SimulationEngine/SimulationManager.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"
#include "Utilities/StatisticsManager.h"
#include "Simulation/Spawners/Spawner.h"

class Application {
public:
    Application();
    ~Application();
    
    void run();

private:
    std::shared_ptr<SettingsCSVReader> reader;
    Grid* grid;
    std::shared_ptr<StatisticsManager> stats;
    Spawner* spawner;
    SimulationManager* manager;
};

#endif // APPLICATION_H
