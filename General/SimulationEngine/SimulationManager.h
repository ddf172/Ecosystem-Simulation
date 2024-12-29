#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include <limits.h>

#include "General/SimulationEngine/Grid.h"

class SimulationManager {
private:
    Grid *grid;
    bool renderGame;
    int maxTurns;

    void updateTiles();
public:
    SimulationManager(Grid *grid);
    void runSimulation();
    void manageTurn();
};



#endif //SIMULATIONMANAGER_H
