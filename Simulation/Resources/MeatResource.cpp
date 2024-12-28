//
// Created by Piotrek on 11.12.2024.
//

#include "MeatResource.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"
#include <climits>

MeatResource::MeatResource(int amount) : Resource(MEAT, amount, std::stoi(SettingsCSVReader::getInstance()->readSettings("Meat", "energyValue"))) {
    this->maxAmount = INT_MAX;
}

MeatResource::MeatResource(int amount, int energyValue) : Resource(MEAT, amount, energyValue) {
    this->maxAmount = INT_MAX;
}
