//
// Created by Piotrek on 29.10.2024.
//

#include "MeatResource.h"

MeatResource::MeatResource(int energyValue1, ResourceType type, int energyValue, int amount) {
    this->energyValue = energyValue;
    this->amountLeft = amount;
    this->type = MEAT;
}

MeatResource::~MeatResource() = default;

int MeatResource::eatResource() {
    if (this->type == EMPTY) {
        return 0;
    }
    this->amountLeft--;
    if (this->amountLeft <= 0) {
        this->type = EMPTY;
    }
    return energyValue;
}
