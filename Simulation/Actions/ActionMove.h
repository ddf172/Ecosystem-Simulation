#ifndef ECOSYSTEM_SIMULATION_ACTIONMOVE_H
#define ECOSYSTEM_SIMULATION_ACTIONMOVE_H

#include "Action.h"


class ActionMove : public Action{
private:
    int x;
    int y;

public:
    ActionMove(int x, int y);
    int getX() const;
    int getY() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONMOVE_H
