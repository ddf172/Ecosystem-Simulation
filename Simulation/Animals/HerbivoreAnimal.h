//
// Created by Piotrek on 03.11.2024.
//

#ifndef HERBIVOREANIMAL_H
#define HERBIVOREANIMAL_H

#include <vector>
#include "Animal.h"
#include "Simulation/Actions/ActionMove.h"
#include "Simulation/Actions/ActionEat.h"
#include "Utilities/Utilities.h"



class HerbivoreAnimal: public Animal {
public:

    HerbivoreAnimal(int id, int startX, int startY);

    HerbivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                    int sightRange, int strength, int maxEatAmount, int health, int maxHealth);

    Action* chooseEatAction(Tile* currentTile);

    Action* chooseMoveActionToNearestTileWithFood(std::vector<Tile*> &surroundingTiles);

    Action* chooseAction(std::vector<Tile*> &surroundingTiles);

    ~HerbivoreAnimal();
};



#endif //HERBIVOREANIMAL_H
