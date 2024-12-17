//
// Created by ddf on 11.12.2024.
//

#include "DieActionChooserDefault.h"

std::shared_ptr<Action> DieActionChooserDefault::chooseAction(Animal* animal) {
    if (!animal || animal->isAlive()) {
        return nullptr;
    }

    int resourceAmount = animal->getMaxHealth() / 2 + animal->getCurrentEnergy() / 2;
    return std::make_shared<ActionDie>(resourceAmount);
}