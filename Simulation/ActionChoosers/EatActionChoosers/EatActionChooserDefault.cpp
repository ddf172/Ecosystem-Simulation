#include "EatActionChooserDefault.h"
#include <memory>

EatActionChooserDefault::EatActionChooserDefault(Tile* currentTile) : currentTile(currentTile) {}

Action* EatActionChooserDefault::chooseAction(Animal* animal) {
    std::unique_ptr<std::vector<Resource*>> resourcesOnTile(currentTile->getResourcesOnTile());

    std::vector<ResourceType> foodTypes = animal->getFoodTypes();
    std::pair<Resource*, int> bestResource = std::make_pair(nullptr, 0);

    for (auto& resource : *resourcesOnTile) {
        if (std::find(foodTypes.begin(), foodTypes.end(), resource->getType()) != foodTypes.end()) {
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