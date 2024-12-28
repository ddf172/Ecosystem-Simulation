//
// Created by Piotrek on 11.12.2024.
//

#include "MeatResource.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"
#include <climits>

MeatResource::MeatResource(int amount) : Resource(MEAT, amount, std::stoi(SettingsCSVReader::getInstance()->readSettings("Meat", "energyValue"))) {
    this->maxAmount = INT_MAX;
    this->decomposingRate = std::stoi(SettingsCSVReader::getInstance()->readSettings("Meat", "decomposingRate"));
}

MeatResource::MeatResource(int amount, int energyValue) : Resource(MEAT, amount, energyValue) {
    this->maxAmount = INT_MAX;
}

int MeatResource::getDecomposingRate() {
    return this->decomposingRate;
}

void MeatResource::decompose() {
    this->amount = std::max(0,this->getAmount() - this->getDecomposingRate());
}

