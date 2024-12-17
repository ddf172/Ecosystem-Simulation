#include "EatActionChooserDefault.h"

EatActionChooserDefault::EatActionChooserDefault(std::shared_ptr<Tile>& currentTile) {
    this->currentTile = currentTile;
}

EatActionChooserDefault::EatActionChooserDefault() : currentTile(nullptr) {}

std::shared_ptr<Action> EatActionChooserDefault::chooseAction(std::weak_ptr<Animal> animal) {
    assert(currentTile != nullptr);

    auto animalPtr = animal.lock();
    if (!animalPtr) {
        return nullptr;
    }

    int resourceAmountThreshold = 20;
    std::vector<std::shared_ptr<Resource>>* resourcesOnTile(currentTile->getResourcesOnTile());

    std::vector<ResourceType> foodTypes = animalPtr->getFoodTypes();
    std::pair<std::shared_ptr<Resource>, int> bestResource = std::make_pair(nullptr, 0);

    for (auto& resource : *resourcesOnTile) {
        if (std::find(foodTypes.begin(), foodTypes.end(), resource->getType()) != foodTypes.end()) {
            if (resource->getAmount() < resourceAmountThreshold) {
                continue;
            }

            int eatAmount = animalPtr->calculateAmountToEat(*resource);
            if (eatAmount * resource->getEnergyValue() > bestResource.second) {
                bestResource = std::make_pair(resource, eatAmount * resource->getEnergyValue());
            }
        }
    }

    if (bestResource.first != nullptr) {
        return std::make_shared<ActionEat>(
                animalPtr->calculateAmountToEat(*bestResource.first),
                bestResource.first->getType()
        );
    }

    return nullptr;
}

void EatActionChooserDefault::setCurrentTile(std::shared_ptr<Tile>& newCurrentTile) {
    currentTile = newCurrentTile;
}