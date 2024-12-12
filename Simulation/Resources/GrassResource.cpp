//
// Created by Piotrek on 29.10.2024.
//

#include "GrassResource.h"



GrassResource::GrassResource(int amount, int energyValue, int regrowAmount, int regrowCooldown)
: Resource(GRASS, amount, energyValue) {
    this->regrowAmount = regrowAmount;
    this->currentRegrowCooldown = regrowCooldown;
    this->maxRegrowCooldown = regrowCooldown;
}

int GrassResource::getCurrentRegrowCooldown() const {
    return currentRegrowCooldown;
}

int GrassResource::getRegrowAmount() const {
    return regrowAmount;
}

void GrassResource::setCurrentRegrowCooldown(int newRegrowCooldown) {
    this->currentRegrowCooldown = newRegrowCooldown;
}

void GrassResource::setRegrowAmount(int newRegrowAmount) {
    this->regrowAmount = newRegrowAmount;
}

void GrassResource::regenerate() {
    if (this->currentRegrowCooldown <= 0) {
        this->currentRegrowCooldown = this->maxRegrowCooldown;

        this->amount += this->getRegrowAmount();

        // clamp
        if (this->amount < 0) this->amount = 0;
        else if (this->amount > this->maxAmount) this->amount = this->maxAmount;

    } else {
        this->currentRegrowCooldown--;
    }
}
