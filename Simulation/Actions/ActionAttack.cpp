#include "ActionAttack.h"

ActionAttack::ActionAttack(int x, int y, int damage, std::shared_ptr<Animal> targetAnimal) : ActionMove(x, y) {
    this->damage = damage;
    this->targetAnimal = targetAnimal;
    this->type = ActionType::ATTACK;
}

int ActionAttack::getDamage() const {
    return this->damage;
}

std::shared_ptr<Animal> ActionAttack::getTargetAnimal() const {
    return this->targetAnimal;
}