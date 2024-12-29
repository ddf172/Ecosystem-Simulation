#ifndef ECOSYSTEM_SIMULATION_ACTION_H
#define ECOSYSTEM_SIMULATION_ACTION_H
#include "ActionTypeEnum.h"


class Action {
protected:
    ActionType type;

public:
    Action(ActionType type);
    virtual ~Action() = default;
    ActionType getType();
};


#endif //ECOSYSTEM_SIMULATION_ACTION_H
