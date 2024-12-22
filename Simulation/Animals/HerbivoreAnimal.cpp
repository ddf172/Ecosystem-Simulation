#include "HerbivoreAnimal.h"
#include "Utilities/Utilities.h"

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY) :
        Animal(id, startX, startY, 5, 50, 100, 5, 1, AnimalType::HERBIVORE,
               25, 100, 100, {ResourceType::GRASS}, {}) {
    initializeBrain();
}

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                                 int sightRange, int strength, int maxEatAmount, int health, int maxHealth) :
        Animal(id, startX, startY, speed, currentEnergy, maxEnergy, sightRange, strength, AnimalType::HERBIVORE,
               maxEatAmount, health, maxHealth, {ResourceType::GRASS}, {}) {
    initializeBrain();
}

void HerbivoreAnimal::initializeBrain() {
    brain = std::make_unique<Brain>(this);

    brain->addActionChooser(new DieActionChooserDefault());
    brain->addActionChooser(new ReproduceActionChooserSoloDefault());
    brain->addActionChooser(new EatActionChooserDefault());
    brain->addActionChooser(new MoveActionChooserNearestResourceTile());
}

std::shared_ptr<Action> HerbivoreAnimal::chooseAction(std::vector<std::shared_ptr<Tile>> &surroundingTiles) {
    std::shared_ptr<Tile> currentTile = getCurrentPositionTile(surroundingTiles, getX(), getY());
    std::vector<std::shared_ptr<Tile>> tilesWithResources = getTilesWithResources(surroundingTiles, {ResourceType::GRASS}, 20);

    for (auto &actionChooser : brain->getActionChoosers()) {
        if (auto *eatActionChooser = dynamic_cast<EatActionChooserDefault*>(actionChooser.get())) {
            eatActionChooser->setCurrentTile(currentTile);
        }
        if (auto *moveActionChooser = dynamic_cast<MoveActionChooserNearestResourceTile*>(actionChooser.get())) {
            moveActionChooser->setTilesWithResources(tilesWithResources);
        }
        if (auto *reproduceActionChooser = dynamic_cast<ReproduceActionChooserSoloDefault*>(actionChooser.get())) {
            reproduceActionChooser->setCurrentTile(currentTile);
        }
    }

    return brain->chooseAction();
}

HerbivoreAnimal::~HerbivoreAnimal() = default;