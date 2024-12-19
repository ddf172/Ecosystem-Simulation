//
// Created by ddf on 18.12.2024.
//

#include "AttackActionChooserDefault.h"


AttackActionChooserDefault::AttackActionChooserDefault() {
    this->currentTile = nullptr;
}

std::shared_ptr<Action> AttackActionChooserDefault::chooseAction(Animal *animal) {
    if (!animal || !animal->isAlive()) {
        return nullptr;
    }
    assert(currentTile != nullptr);

    std::vector<AnimalType> attackTypes = animal->getAttackTypes();
    std::vector<std::shared_ptr<Animal>>* animalsOnTile = currentTile->getAnimalsOnTile();
    for (auto& animalOnTile : *animalsOnTile) {
        if (std::find(attackTypes.begin(), attackTypes.end(), animalOnTile->getType()) != attackTypes.end()) {
            return std::make_shared<ActionAttack>(animalOnTile->getId(), animal->getStrength());
        }
    }

    return nullptr;
}

void AttackActionChooserDefault::setCurrentTile(std::shared_ptr<Tile>& tile) {
    this->currentTile = tile;
}