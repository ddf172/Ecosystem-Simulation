//
// Created by Piotrek on 29.10.2024.
//

#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include <limits.h>

#include "Grid.h"

class SimulationManager {
private:
    Grid *grid;
    bool renderGame;
    int maxTurns;
public:
    SimulationManager(Grid *grid, bool renderGame = true, int maxTurns = INT_MAX);
    void runSimulation();
    void manageTurn();
};



#endif //SIMULATIONMANAGER_H
