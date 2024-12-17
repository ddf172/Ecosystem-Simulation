//
// Created by ddf on 11.12.2024.
//

#include "DieActionChooserDefault.h"

std::shared_ptr<Action> DieActionChooserDefault::chooseAction(std::weak_ptr<Animal> animal) {
    auto animalPtr = animal.lock();
    if (!animalPtr || animalPtr->isAlive()) {
        return nullptr;
    }

    int resourceAmount = animalPtr->getMaxHealth() / 2 + animalPtr->getCurrentEnergy() / 2;
    return std::make_shared<ActionDie>(resourceAmount);
}