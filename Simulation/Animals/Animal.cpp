//
// Created by Piotrek on 29.10.2024.
//

#include "Animal.h"

#include <iostream>

Animal::Animal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
               int sightRange, int strength, AnimalType type, int maxEatAmount, int health, int maxHealth) {
    this->id = id;
    this->posX = startX;
    this->posY = startY;
    this->currentEnergy = currentEnergy;
    this->maxEnergy = maxEnergy;
    this->speed = speed;
    this->sightRange = sightRange;
    this->strength = strength;
    this->type = type;
    this->maxEatAmount = maxEatAmount;
    this->health = health;
    this->maxHealth = maxHealth;
}

int Animal::calculateAmountToEat(Resource &resource) const {
    int missingEnergy = maxEnergy - currentEnergy;
    int maxEatAmountLocal = int(missingEnergy/resource.getEnergyValue());
    return std::min(std::min(maxEatAmountLocal, maxEatAmount), resource.getAmount());

}

int Animal::getX() const {
    return posX;
}

int Animal::getY() const {
    return posY;
}

int Animal::getCurrentEnergy() const {
    return currentEnergy;
}

int Animal::getMaxEnergy() const {
    return maxEnergy;
}

int Animal::getSightRange() const {
    return sightRange;
}

int Animal::getHealth() const {
    return health;
}

int Animal::getSpeed() const {
    return speed;
}

AnimalType Animal::getType() {
    return type;
}

void Animal::move(int desX, int desY) {
    posX = desX;
    posY = desY;
}

void Animal::eat(int increase) {
    currentEnergy += std::min(increase, maxEnergy - currentEnergy);
}

Animal::~Animal() = default;

int Animal::calculateEnergyLoss(Action *action) {
    switch (action->getType()) {
        case ActionType::NONE:
            return 0;
        case ActionType::MOVE:{
            auto* moveAction = dynamic_cast<ActionMove*>(action);
            int val = int(calculateDistance(posX, posY, moveAction->getX(), moveAction->getY()) * 0.1);
            return val;
        }
        default:
            return 0;
    }
}

void Animal::executeAction(Action *action) {
    switch (action->getType()) {
        case ActionType::NONE:
            break;
        case ActionType::MOVE:{
            auto* moveAction = dynamic_cast<ActionMove*>(action);
            move(moveAction->getX(), moveAction->getY());
            currentEnergy -= calculateEnergyLoss(action);
            break;
        }
        case ActionType::EAT:{
            auto* eatAction = dynamic_cast<ActionEat*>(action);
            eat(eatAction->getAmount());
            currentEnergy -= calculateEnergyLoss(eatAction);
            break;
        }
        case ActionType::DIE:{
            health = 0;
            break;
        }
        default:
            break;
    }

    currentEnergy -= 10;
}

Action* Animal::isAlive() const {
    int resourceAmount = maxHealth / 2 + currentEnergy / 2;
    if (this->health <= 0 || this->currentEnergy <= 0) {
        return new ActionDie(resourceAmount);
    }
    return nullptr;
}