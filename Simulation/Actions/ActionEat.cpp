//
// Created by jakub on 18.11.2024.
//

#include "ActionEat.h"

ActionEat::ActionEat(int number, ResourceType resourceType) : Action(EAT) {
    this->number = number;
    this->resourceType = resourceType;
}

int ActionEat::getNumber() const {
    return this->number;
}

ResourceType ActionEat::getResourceType() {
    return this->resourceType;
}