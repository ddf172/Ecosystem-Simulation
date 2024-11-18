//
// Created by jakub on 17.11.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTION_H
#define ECOSYSTEM_SIMULATION_ACTION_H
#include "ActionTypeEnum.h"


class Action {
protected:
    actionType type;

public:
    Action(actionType type);
    virtual ~Action() = default;
    actionType getType();
};


#endif //ECOSYSTEM_SIMULATION_ACTION_H
