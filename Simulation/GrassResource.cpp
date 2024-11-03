//
// Created by Piotrek on 29.10.2024.
//

#include "GrassResource.h"



GrassResource::GrassResource(int energyValue, int maxRegrowCooldown) {
    this->currentRegrowCooldown = 0;
    this->energyValue = energyValue;
    this->maxRegrowCooldown = maxRegrowCooldown;
    this->type = GRASS;
}

int GrassResource::eatResource() {
    if (this->type == GRASS) {
        currentRegrowCooldown = maxRegrowCooldown;
        this->type = EMPTY_GRASS;
        return energyValue;
    }
    return 0;
}

void GrassResource::decrementRegrowCooldown() {
    this->currentRegrowCooldown--;
    if (currentRegrowCooldown <= 0) {
        this->currentRegrowCooldown = 0;
        this->type = GRASS;
    } else {
        this->type = EMPTY_GRASS;
    }
}


