#include "EatActionChooserDefault.h"

EatActionChooserDefault::EatActionChooserDefault(std::shared_ptr<Tile> currentTile)
        : currentTile(std::move(currentTile)) {}

EatActionChooserDefault::EatActionChooserDefault() : currentTile(nullptr) {}

Action* EatActionChooserDefault::chooseAction(Animal* animal) {
    assert(currentTile != nullptr);

    int resourceAmountThreshold = 20;
    std::vector<Resource*>* resourcesOnTile(currentTile->getResourcesOnTile());

    std::vector<ResourceType> foodTypes = animal->getFoodTypes();
    std::pair<Resource*, int> bestResource = std::make_pair(nullptr, 0);

    for (auto& resource : *resourcesOnTile) {
        if (std::find(foodTypes.begin(), foodTypes.end(), resource->getType()) != foodTypes.end()) {
            if (resource->getAmount() < resourceAmountThreshold) {
                continue;
            }

            int eatAmount = animal->calculateAmountToEat(*resource);
            if (eatAmount * resource->getEnergyValue() > bestResource.second) {
                bestResource = std::make_pair(resource, eatAmount * resource->getEnergyValue());
            }
        }
    }

    if (bestResource.first != nullptr) {
        return new ActionEat(
                animal->calculateAmountToEat(*bestResource.first),
                bestResource.first->getType()
        );
    }

    return nullptr;
}

void EatActionChooserDefault::setCurrentTile(Tile* newCurrentTile) {
    currentTile = std::shared_ptr<Tile>(newCurrentTile);
}