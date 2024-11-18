//
// Created by Piotrek on 29.10.2024.
//

#include "Resource.h"

Resource::Resource(ResourceType type, int amount, int energyValue) {
    this->type = type;
    this->amount = amount;
    this->energyValue = energyValue;
}

ResourceType Resource::getType() {
    return type;
}

int Resource::getAmount() const {
    return amount;
}

int Resource::getEnergyValue() const {
    return energyValue;
}

void Resource::setAmount(int newAmount) {
    this->amount = newAmount;
}

void Resource::setEnergyValue(int newEnergyValue) {
    this->energyValue = newEnergyValue;
}
