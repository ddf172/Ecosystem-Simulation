//
// Created by jakub on 18.11.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONEAT_H
#define ECOSYSTEM_SIMULATION_ACTIONEAT_H

#include "Simulation/Resources/Resource.h"
#include "Action.h"


class ActionEat : public Action {
private:
    int amount;
    ResourceType resourceType;

public:
    ActionEat(int number, ResourceType resourceType);
    int getAmount() const;
    ResourceType getResourceType();
};


#endif //ECOSYSTEM_SIMULATION_ACTIONEAT_H
