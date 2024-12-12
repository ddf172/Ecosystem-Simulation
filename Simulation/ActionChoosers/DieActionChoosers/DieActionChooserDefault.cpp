//
// Created by ddf on 11.12.2024.
//

#include "DieActionChooserDefault.h"
#include <iostream>

Action* DieActionChooserDefault::chooseAction(Animal* animal) {
    if (!animal->isAlive()) {
        int resourceAmount = animal->getMaxHealth() / 2 + animal->getCurrentEnergy() / 2;
        return new ActionDie(resourceAmount);
    }
    return nullptr;
}