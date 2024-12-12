//
// Created by Piotrek on 11.12.2024.
//

#include "MeatResource.h"

#include <climits>

MeatResource::MeatResource(int amount, int energyValue) : Resource(MEAT, amount, energyValue) {
    this->maxAmount = INT_MAX;
}
