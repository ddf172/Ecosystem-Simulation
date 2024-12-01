//
// Created by Piotrek on 29.10.2024.
//

#include "Resource.h"

Resource::Resource(ResourceType type, int amount, int energyValue) {
    this->type = type;
    this->amount = amount;
    this->energyValue = energyValue;
    this->maxAmount = amount;
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
    // clamp
    if (this->amount < 0) this->amount = 0;
    if (this->amount > this->maxAmount) this->amount = this->maxAmount;
}

void Resource::setEnergyValue(int newEnergyValue) {
    this->energyValue = newEnergyValue;
}

int Resource::getMaxAmount() const {
    return this->maxAmount;
}