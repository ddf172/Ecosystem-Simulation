//
// Created by Piotrek on 29.10.2024.
//

#include "Animal.h"

Animal::Animal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
               int sightRange, int strength, AnimalType type, int maxEatAmount, int health, int maxHealth, std::vector<ResourceType> foodTypes)
        : id(id), posX(startX), posY(startY), currentEnergy(currentEnergy), maxEnergy(maxEnergy),
          speed(speed), sightRange(sightRange), strength(strength), type(type), maxEatAmount(maxEatAmount),
          health(health), maxHealth(maxHealth), foodTypes(std::move(foodTypes)), brain(nullptr) {
}

int Animal::calculateAmountToEat(Resource &resource) const {
    int missingEnergy = maxEnergy - currentEnergy;
    int maxEatAmountLocal = int(missingEnergy/resource.getEnergyValue());
    return std::min(std::min(maxEatAmountLocal, maxEatAmount), resource.getAmount());
}

int Animal::getId() const {
    return id;
}

bool Animal::isAlive() const {
    return health > 0 && currentEnergy > 0;
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

int Animal::getMaxHealth() const {
    return maxHealth;
}

int Animal::getSpeed() const {
    return speed;
}

AnimalType Animal::getType() {
    return type;
}

std::vector<ResourceType> Animal::getFoodTypes() const {
    return foodTypes;
}

void Animal::move(int desX, int desY) {
    posX = desX;
    posY = desY;
}

void Animal::eat(int increase) {
    currentEnergy += std::min(increase, maxEnergy - currentEnergy);
}

Animal::~Animal() {
    brain = nullptr;
}

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

void Animal::executeAction(std::shared_ptr<Action> action) {
    switch (action->getType()) {
        case ActionType::NONE:
            break;
        case ActionType::MOVE: {
            auto* moveAction = dynamic_cast<ActionMove*>(action.get());
            move(moveAction->getX(), moveAction->getY());
            currentEnergy -= calculateEnergyLoss(action.get());
            break;
        }
        case ActionType::EAT: {
            auto* eatAction = dynamic_cast<ActionEat*>(action.get());
            eat(eatAction->getAmount());
            currentEnergy -= calculateEnergyLoss(eatAction);
            break;
        }
        case ActionType::DIE: {
            health = 0;
            break;
        }
        default:
            break;
    }

    currentEnergy -= 10;
}