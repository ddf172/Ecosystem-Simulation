//
// Created by Piotrek on 29.10.2024.
//

#include "Animal.h"

Animal::Animal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength, AnimalType type) {
    this->id = id;
    this->posX = startX;
    this->posY = startY;
    this->currentEnergy = int(maxEnergy/2);
    this->maxEnergy = maxEnergy;
    this->speed = speed;
    this->sightRange = sightRange;
    this->strength = strength;
    this->type = type;
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
    currentEnergy += std::min(increase, maxEnergy);
}

Animal::~Animal() = default;

int Animal::calculateEnergyLoss(Action *action) {
    switch (action->getType()) {
        case ActionType::NONE:
            return 0;
        case ActionType::MOVE:{
            auto* moveAction = dynamic_cast<ActionMove*>(action);
            return int(calculateDistance(posX, posY, moveAction->getX(), moveAction->getY()));

        }
        case ActionType::EAT:{
            auto* eatAction = dynamic_cast<ActionEat*>(action);
            return int(eatAction->getAmount() * 0.1);
        }
        default:
            return 0;
    }
}