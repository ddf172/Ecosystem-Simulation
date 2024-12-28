#ifndef SPAWNER_H
#define SPAWNER_H

#include <memory>
#include "General/Grid.h"
#include "Utilities/StatisticsManager.h"

class Spawner {
private:
    Grid* grid;
    std::shared_ptr<StatisticsManager> stats;
    void spawnHerbivore(int i, int j);
    void spawnCarnivore(int i, int j);
    float getRandomNumber();
    float herbivorePercent;
    float carnivorePercent;

public:
    Spawner(Grid* grid, std::shared_ptr<StatisticsManager> stats);

    void populateGrid();
};

#endif // SPAWNER_H
