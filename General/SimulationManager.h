//
// Created by Piotrek on 29.10.2024.
//

#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "Grid.h"


class SimulationManager {
private:
    Grid *grid;
    int maxTurns;
    bool renderGame;
public:
    SimulationManager(Grid *grid, int maxTurns, bool renderGame);
    void runSimulation();
    void setRenderGame(bool val);
    void setMaxTurns(int val);
    void manageTurn();
};



#endif //SIMULATIONMANAGER_H
