//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONBREED_H
#define ECOSYSTEM_SIMULATION_ACTIONBREED_H

#include "Action.h"

class ActionBreed : public Action {
    int offSpringNumber;
    int energyCost;
public:
    ActionBreed(int offSpringNumber, int energyCost);

    int getOffSpringNumber() const;
    int getEnergyCost() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONBREED_H
