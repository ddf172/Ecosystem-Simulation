//
// Created by Piotrek on 29.10.2024.
//
#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>
#include "General/SimulationEngine/Tile.h"
#include "Simulation/Actions/Action.h"
#include "AnimalTypeEnum.h"
#include "Simulation/Actions/ActionTypeEnum.h"
#include "Simulation/Actions/ActionMove.h"
#include "Simulation/Actions/ActionEat.h"
#include "Simulation/Actions/ActionDie.h"
#include "Simulation/Actions/ActionAttack.h"
#include "Simulation/Actions/ActionReproduce.h"
#include "Utilities/Utilities.h"
#include "../Brains/Brain.h"
#include <memory>

class Tile;
class Brain;

class Animal{
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
    std::unique_ptr<Brain> brain;
    std::vector<AnimalType> attackTypes;
    virtual void initializeBrain() = 0;
public:
    Animal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
           int sightRange, int strength, AnimalType type, int maxEatAmount, int health, int maxHealth, std::vector<ResourceType> foodTypes,
           std::vector<AnimalType> attackTypes);
    int getId() const;
    int getX() const;
    int getY() const;
    int getCurrentEnergy() const;
    int getMaxEnergy() const;
    int getSpeed() const;
    int getHealth() const;
    void setHealth(int amount);
    int getMaxHealth() const;
    int getSightRange() const;
    std::vector<ResourceType> getFoodTypes() const;
    AnimalType getType();
    int calculateAmountToEat(Resource& resource) const;
    bool isAlive() const;
    std::vector<AnimalType> getAttackTypes() const;
    int getStrength() const;

    virtual std::shared_ptr<Action> chooseAction(std::vector<std::shared_ptr<Tile>>& surroundingTiles) = 0;
    virtual void move(int desX, int desY);
    virtual void eat(int increase);

    virtual int calculateEnergyLoss(Action *action);
    virtual void executeAction(std::shared_ptr<Action> action);

    virtual ~Animal();
};

#endif //ANIMAL_H