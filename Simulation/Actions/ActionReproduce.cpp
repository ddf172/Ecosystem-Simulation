//
// Created by ddf on 18.12.2024.
//

#include "ActionReproduce.h"

ActionReproduce::ActionReproduce(int offSpringNumber, int energyCost) : offSpringNumber(offSpringNumber), energyCost(energyCost), Action(ActionType::REPRODUCE) {}

int ActionReproduce::getOffSpringNumber() const {
    return offSpringNumber;
}

int ActionReproduce::getEnergyCost() const {
    return energyCost;
}