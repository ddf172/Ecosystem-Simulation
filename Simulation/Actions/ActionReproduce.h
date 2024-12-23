//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONREPRODUCE_H
#define ECOSYSTEM_SIMULATION_ACTIONREPRODUCE_H

#include "Action.h"

class ActionReproduce : public Action {
    int offSpringNumber;
public:
    explicit ActionReproduce(int offSpringNumber);

    int getOffSpringNumber() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONREPRODUCE_H
