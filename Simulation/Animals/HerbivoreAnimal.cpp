#include "HerbivoreAnimal.h"

#include <iostream>

#include "Simulation/Resources/GrassResource.h"

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY) :
Animal(id, startX, startY, 5, 50, 100, 5, 1, AnimalType::HERBIVORE,
       25, 100, 100, {ResourceType::GRASS}){}

HerbivoreAnimal::HerbivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                                 int sightRange, int strength, int maxEatAmount, int health, int maxHealth) :
Animal(id, startX, startY, speed, currentEnergy, maxEnergy, sightRange, strength, AnimalType::HERBIVORE, maxEatAmount, health, maxHealth, {ResourceType::GRASS}){}


Action* HerbivoreAnimal::chooseAction(std::vector<Tile*> &surroundingTiles){
    Tile *currentTile = getCurrentPositionTile(surroundingTiles, getX(), getY());
    std::vector<Tile*> tilesWithResources = getTilesWithResources(surroundingTiles, {GRASS}, 20);
    Brain brain(this);
    brain.addActionChooser(new DieActionChooserDefault());
    brain.addActionChooser(new EatActionChooserDefault(currentTile));
    brain.addActionChooser(new MoveActionChooserNearestResourceTile(tilesWithResources));
    return brain.chooseAction();
}

HerbivoreAnimal::~HerbivoreAnimal() = default;