//
// Created by Piotrek on 29.10.2024.
//

#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "Grid.h"

class SimulationManager {
private:
    Grid *grid;
public:
    SimulationManager(Grid *grid);
    void runSimulation();
    void manageTurn();
};



#endif //SIMULATIONMANAGER_H
