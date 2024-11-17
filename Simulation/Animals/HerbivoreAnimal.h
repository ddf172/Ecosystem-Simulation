//
// Created by Piotrek on 03.11.2024.
//

#ifndef HERBIVOREANIMAL_H
#define HERBIVOREANIMAL_H

#include <vector>
#include "Animal.h"
#include "General/Tile.h"
#include "Utilities/Utilities.h"



class HerbivoreAnimal: public Animal {

    HerbivoreAnimal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength);

    void chooseAction(std::vector<Tile*>) override;
};



#endif //HERBIVOREANIMAL_H
