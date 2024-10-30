//
// Created by Piotrek on 29.10.2024.
//

#include "GrassResource.h"

GrassResource::GrassResource(int energyValue, int maxRegrowTime) {
    this->currentRegrowTime = maxRegrowTime;
    this->energyValue = energyValue;
    this->maxRegrowTime = maxRegrowTime;
    this->type = GRASS;
}

