//
// Created by ddf on 18.12.2024.
//

#include "ActionBreed.h"

ActionBreed::ActionBreed(int offSpringNumber, int energyCost) : offSpringNumber(offSpringNumber), energyCost(energyCost), Action(ActionType::BREED) {}

int ActionBreed::getOffSpringNumber() const {
    return offSpringNumber;
}

int ActionBreed::getEnergyCost() const {
    return energyCost;
}