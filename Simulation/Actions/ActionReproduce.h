//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONREPRODUCE_H
#define ECOSYSTEM_SIMULATION_ACTIONREPRODUCE_H

#include "Action.h"

class ActionReproduce : public Action {
    int offSpringNumber;
    int energyCost;
public:
    ActionReproduce(int offSpringNumber, int energyCost);

    int getOffSpringNumber() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONREPRODUCE_H
