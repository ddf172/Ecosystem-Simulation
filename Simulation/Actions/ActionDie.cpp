//
// Created by jakub on 30.11.2024.
//

#include "ActionDie.h"

ActionDie::ActionDie(int resourceAmount) : Action(ActionType::DIE) {
    this->resourceAmount = resourceAmount;
}

ActionDie::~ActionDie() = default;

int ActionDie::getResourceAmount() const {
    return this->resourceAmount;
}