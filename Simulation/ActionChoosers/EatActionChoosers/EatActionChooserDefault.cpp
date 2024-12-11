//
// Created by jakub on 11.12.2024.
//

#include "EatActionChooserDefault.h"

EatActionChooserDefault::EatActionChooserDefault(Tile* currentTile) : currentTile(currentTile) {}

Action* EatActionChooserDefault::chooseAction(Animal* animal) {
    std::vector<Resource*>* resourcesOnTile = currentTile->getResourcesOnTile();
    return nullptr;
}
