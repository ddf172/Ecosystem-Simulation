//
// Created by jakub on 30.11.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONDIE_H
#define ECOSYSTEM_SIMULATION_ACTIONDIE_H

#include "Action.h"

class ActionDie : public Action{
private:
    int resourceAmount;
public:
    ActionDie(int resourceAmount);
    ~ActionDie() override;
    int getResourceAmount() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONDIE_H
