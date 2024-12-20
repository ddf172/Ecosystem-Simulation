//
// Created by ddf on 18.12.2024.
//

#include "AttackActionChooserDefault.h"


AttackActionChooserDefault::AttackActionChooserDefault() {
    this->targetTiles = new std::vector<std::shared_ptr<Tile>>();
}

std::shared_ptr<Action> AttackActionChooserDefault::chooseAction(Animal *animal) {
    if (!animal || !animal->isAlive()) {
        return nullptr;
    }
    if (targetTiles->empty()) {
        return nullptr;
    }

    std::shared_ptr<Tile> closestTargetTile = *std::min_element(targetTiles->begin(), targetTiles->end(), [animal](const std::shared_ptr<Tile>& a, const std::shared_ptr<Tile>& b) {
        int distanceA = calculateDistance(animal->getX(), animal->getY(), a->getX(), a->getY());
        int distanceB = calculateDistance(animal->getX(), animal->getY(), b->getX(), b->getY());
        return distanceA < distanceB;
    });

    std::vector<std::shared_ptr<Animal>>* animalsOnTile = closestTargetTile->getAnimalsOnTile();
    if (!animalsOnTile->empty()) {
        std::shared_ptr<Animal> targetAnimal = animalsOnTile->at(0);
        return std::make_shared<ActionAttack>(closestTargetTile->getX(), closestTargetTile->getY(), animal->getStrength(), targetAnimal);
    }
    return nullptr;
}

void AttackActionChooserDefault::setTargetTiles(std::vector<std::shared_ptr<Tile>> *newTargetTiles) {
    this->targetTiles = newTargetTiles;
}