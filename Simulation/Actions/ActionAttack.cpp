//
// Created by ddf on 18.12.2024.
//

#include "ActionAttack.h"

ActionAttack::ActionAttack(int damage, std::shared_ptr<Animal> targetAnimal) : Action(ATTACK) {
    this->damage = damage;
    this->targetAnimal = targetAnimal;
}

int ActionAttack::getDamage() const {
    return this->damage;
}

std::shared_ptr<Animal> ActionAttack::getTargetAnimal() const {
    return this->targetAnimal;
}