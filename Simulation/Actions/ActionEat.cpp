#include "ActionEat.h"

ActionEat::ActionEat(int amount, ResourceType resourceType) : Action(EAT) {
    this->amount = amount;
    this->resourceType = resourceType;
}

int ActionEat::getAmount() const {
    return this->amount;
}

ResourceType ActionEat::getResourceType() const {
    return this->resourceType;
}