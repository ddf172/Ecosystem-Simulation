//
// Created by Piotrek on 29.10.2024.
//
#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>
#include "General/Tile.h"
#include "Simulation/Actions/Action.h"
#include "AnimalTypeEnum.h"
#include "Simulation/Actions/ActionTypeEnum.h"
#include "Simulation/Actions/ActionMove.h"
#include "Simulation/Actions/ActionEat.h"
#include "Simulation/Actions/ActionDie.h"
#include "Utilities/Utilities.h"
#include "../Brains/Brain.h"

class Tile;
class Brain;

class Animal {
protected:
    int id;
    int posX;
    int posY;
    int speed;
    int currentEnergy;
    int maxEnergy;
    int sightRange;
    int strength;
    int health;
    int maxHealth;
    AnimalType type;
    int maxEatAmount;
    std::vector<ResourceType> foodTypes;
    Brain* brain;
    virtual void initializeBrain() = 0;
public:
    Animal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
           int sightRange, int strength, AnimalType type, int maxEatAmount, int health, int maxHealth, std::vector<ResourceType> foodTypes);
    int getId() const;
    int getX() const;
    int getY() const;
    int getCurrentEnergy() const;
    int getMaxEnergy() const;
    int getSpeed() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getSightRange() const;
    std::vector<ResourceType> getFoodTypes() const;
    AnimalType getType();
    int calculateAmountToEat(Resource& resource) const;
    bool isAlive() const;

    virtual Action* chooseAction(std::vector<Tile*>& surroundingTiles) = 0;
    virtual void move(int desX, int desY);
    virtual void eat(int increase);

    virtual int calculateEnergyLoss(Action *action);
    virtual void executeAction(Action *action);

    virtual ~Animal();
};

#endif //ANIMAL_H