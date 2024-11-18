//
// Created by Piotrek on 29.10.2024.
//

#include "GrassResource.h"



GrassResource::GrassResource(int amount, int energyValue, int regrowAmount, int regrowCooldown)
: Resource(GRASS, amount, energyValue) {
    this->regrowAmount = regrowAmount;
    this->regrowCooldown = regrowCooldown;
}

GrassResource::~GrassResource() = default;

int GrassResource::getRegrowCooldown() const {
    return regrowCooldown;
}

int GrassResource::getRegrowAmount() const {
    return regrowAmount;
}

void GrassResource::setRegrowCooldown(int newRegrowCooldown) {
    this->regrowCooldown = newRegrowCooldown;
}

void GrassResource::setRegrowAmount(int newRegrowAmount) {
    this->regrowAmount = newRegrowAmount;
}