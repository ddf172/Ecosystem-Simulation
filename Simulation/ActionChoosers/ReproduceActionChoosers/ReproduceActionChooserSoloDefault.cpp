//
// Created by ddf on 18.12.2024.
//

#include "ReproduceActionChooserSoloDefault.h"

ReproduceActionChooserSoloDefault::ReproduceActionChooserSoloDefault() : currentTile(nullptr){};

std::shared_ptr<Action> ReproduceActionChooserSoloDefault::chooseAction(Animal* animal) {
    if (!animal || !animal->isAlive()) {
        return nullptr;
    }

    if (animal->getCurrentEnergy() < animal->getMaxEnergy() * 0.7) {
        return nullptr;
    }

    return std::make_shared<ActionReproduce>(1);
}

void ReproduceActionChooserSoloDefault::setCurrentTile(std::shared_ptr<Tile>& newCurrentTile) {
    this->currentTile = newCurrentTile;
}