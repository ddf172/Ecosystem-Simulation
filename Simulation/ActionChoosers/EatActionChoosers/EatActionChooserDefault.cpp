#include "EatActionChooserDefault.h"

EatActionChooserDefault::EatActionChooserDefault(std::shared_ptr<Tile>& currentTile) {
    this->currentTile = currentTile;
}

EatActionChooserDefault::EatActionChooserDefault() : currentTile(nullptr) {}

std::shared_ptr<Action> EatActionChooserDefault::chooseAction(Animal* animal) {
    assert(currentTile != nullptr);
    if (!animal) {
        return nullptr;
    }

    int resourceAmountThreshold = 20;
    std::vector<std::shared_ptr<Resource>>* resourcesOnTile(currentTile->getResourcesOnTile());

    std::vector<ResourceType> foodTypes = animal->getFoodTypes();
    std::pair<std::shared_ptr<Resource>, int> bestResource = std::make_pair(nullptr, 0);

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
        return std::make_shared<ActionEat>(
                animal->calculateAmountToEat(*bestResource.first),
                bestResource.first->getType()
        );
    }

    return nullptr;
}

void EatActionChooserDefault::setCurrentTile(std::shared_ptr<Tile>& newCurrentTile) {
    this->currentTile = newCurrentTile;
}