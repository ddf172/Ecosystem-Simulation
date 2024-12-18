//
// Created by ddf on 18.12.2024.
//

#include "ReproduceActionChooserSoloDefault.h"

std::shared_ptr<Action> BreedActionChooserSoloDefault::chooseAction(Animal* animal) {
    if (!animal || !animal->isAlive()) {
        return nullptr;
    }

    if (animal->getCurrentEnergy() < animal->getMaxEnergy() * 0.7) {
        return nullptr;
    }

    return std::make_shared<ActionReproduce>(1, animal->getMaxEnergy() / 2);
}