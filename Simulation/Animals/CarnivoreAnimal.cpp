#include "CarnivoreAnimal.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"

void CarnivoreAnimal::initializeBrain() {
    brain = std::make_unique<Brain>(this);

    brain->addActionChooser(new DieActionChooserDefault());
    brain->addActionChooser(new ReproduceActionChooserSoloDefault());
    brain->addActionChooser(new EatActionChooserDefault());
    brain->addActionChooser(new MoveActionChooserNearestResourceTile());
    brain->addActionChooser(new AttackActionChooserDefault());
}

CarnivoreAnimal::CarnivoreAnimal(int id, int startX, int startY) : 
    Animal(id, startX, startY,
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "speed")),
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "currentEnergy")),
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "maxEnergy")),
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "sightRange")),
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "strength")),
           AnimalType::CARNIVORE,
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "maxEatAmount")),
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "health")),
           std::stoi(SettingsCSVReader::getInstance()->readSettings("CarnivoreAnimal", "maxHealth")),
           {ResourceType::MEAT},
           {AnimalType::HERBIVORE}) {
    initializeBrain();
}

CarnivoreAnimal::CarnivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                                 int sightRange, int strength, int maxEatAmount, int health, int maxHealth) :
        Animal(id, startX, startY, speed, currentEnergy, maxEnergy, sightRange, strength, AnimalType::CARNIVORE,
               maxEatAmount, health, maxHealth, {ResourceType::MEAT}, {HERBIVORE}) {
    initializeBrain();
}

std::shared_ptr<Action> CarnivoreAnimal::chooseAction(std::vector<std::shared_ptr<Tile>> &surroundingTiles) {
    std::shared_ptr<Tile> currentTile = getCurrentPositionTile(surroundingTiles, getX(), getY());
    std::vector<std::shared_ptr<Tile>> reachableTiles = getReachableTiles(surroundingTiles, speed, getX(), getY());
    std::vector<std::shared_ptr<Tile>> tilesWithResources = getTilesWithResources(reachableTiles, foodTypes, 20);
    std::vector<std::shared_ptr<Tile>> tilesWithTargetAnimals = getTilesWithAnimals(reachableTiles, attackTypes, this);

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
        if (auto *attackActionChooser = dynamic_cast<AttackActionChooserDefault*>(actionChooser.get())) {
            attackActionChooser->setTargetTiles(tilesWithTargetAnimals);
        }
    }

    return brain->chooseAction();
}

CarnivoreAnimal::~CarnivoreAnimal() = default;