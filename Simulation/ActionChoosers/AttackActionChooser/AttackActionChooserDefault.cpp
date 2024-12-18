//
// Created by ddf on 18.12.2024.
//

#include "AttackActionChooserDefault.h"

AttackActionChooserDefault::AttackActionChooserDefault() {
    this->currentTile = nullptr;
}

std::shared_ptr<Action> AttackActionChooserDefault::chooseAction(Animal *animal) {
// implement it later
    return nullptr;
}

void AttackActionChooserDefault::setCurrentTile(std::shared_ptr<Tile>& tile) {
    this->currentTile = tile;
}