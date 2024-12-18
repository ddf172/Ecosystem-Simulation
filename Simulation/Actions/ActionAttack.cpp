//
// Created by ddf on 18.12.2024.
//

#include "ActionAttack.h"

ActionAttack::ActionAttack(int damage, int targetId) : Action(ATTACK) {
    this->damage = damage;
    this->targetId = targetId;
}

int ActionAttack::getDamage() const {
    return this->damage;
}

int ActionAttack::getTargetId() const {
    return this->targetId;
}