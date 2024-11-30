//
// Created by Piotrek on 29.10.2024.
//

#include "Animal.h"

Animal::Animal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength, AnimalType type, int maxEatAmount) {
    this->id = id;
    this->posX = startX;
    this->posY = startY;
    this->currentEnergy = int(maxEnergy/2);
    this->maxEnergy = maxEnergy;
    this->speed = speed;
    this->sightRange = sightRange;
    this->strength = strength;
    this->type = type;
    this->maxEatAmount = maxEatAmount;
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
            int val = int(calculateDistance(posX, posY, moveAction->getX(), moveAction->getY()) * 0.1);
            delete(moveAction);
            return val;
        }
        case ActionType::EAT:{
            auto* eatAction = dynamic_cast<ActionEat*>(action);
            int val = int(eatAction->getAmount() * 0.1);
            delete(eatAction);
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
            delete(moveAction);
            break;
        }
        case ActionType::EAT:{
            auto* eatAction = dynamic_cast<ActionEat*>(action);
            eat(eatAction->getAmount());
            delete(eatAction);
            break;
        }
        default:
            break;
    }
    currentEnergy -= calculateEnergyLoss(action);
}