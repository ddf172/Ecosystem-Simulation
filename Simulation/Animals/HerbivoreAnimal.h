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

    HerbivoreAnimal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength);

    Action* chooseMoveToNearestTileWithFood(std::vector<Tile*>* surroundingTiles);

    Action* chooseAction(std::vector<Tile*>* surroundingTiles);
};



#endif //HERBIVOREANIMAL_H
