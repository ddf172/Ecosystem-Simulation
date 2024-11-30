//
// Created by jakub on 30.11.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONDIE_H
#define ECOSYSTEM_SIMULATION_ACTIONDIE_H

#include "Action.h"

class ActionDie : public Action{
private:
    /**
     * Amount of resources that the entity will drop
     * You have to implement logic of adding resource to the tile in simulation Manager
     */
    int resourceAmount;
public:
    explicit ActionDie(int resourceAmount);
    ~ActionDie() override;
    int getResourceAmount() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONDIE_H
