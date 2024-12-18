//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONATTACK_H
#define ECOSYSTEM_SIMULATION_ACTIONATTACK_H

#include "Action.h"

class ActionAttack : public Action{
private:
    int damage;
    int targetId;

public:
    ActionAttack(int damage, int targetId);
    int getDamage() const;
    int getTargetId() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONATTACK_H
