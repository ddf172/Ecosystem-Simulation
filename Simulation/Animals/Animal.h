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

class Tile;

class Animal {
// Current uncommented code is for testing until
// sensible solution to Animal code structure is implemented
protected:
    // I think id will be useful
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

public:
    Animal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
           int sightRange, int strength, AnimalType type, int maxEatAmount, int health, int maxHealth, std::vector<ResourceType> foodTypes);
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

    /* COMMENT FROM PIT: Mysle ze bedzie git, jezeli zrobimy ten pomysl ze kazdy animal ma 2 dostepne akcje
     * i teraz -> move() - moze byc tylko w pierwszej akcji
     * eat() -> moze byc tylko w pierwszej akcji i druga wtedy przemija (ze jedzenie zajmuje cala ture)
     * attack() -> moze byc w pierwszej i drugiej, np. najpierw move potem attack
     * breed() -> moze byc w pierwszej i drugiej np. najpierw move potem breed
     */
    virtual Action* chooseAction(std::vector<Tile*>& surroundingTiles) = 0;
    /**
    *   Move to the destination coordinates
    */
    virtual void move(int desX, int desY);
    /**
     *  Animal eats resource on the current tile
     */
    virtual void eat(int increase);
    /**
    *  Animal breeds with animal on the current tile if possible
    */
    // virtual void breed();
    /**
    *  Animal attacks other animal on the current tile if possible
    */
    // virtual void attack();

    /**
     * @brief Function that calculates energy loss of the animal based on chosen action and statistics of the animal.
     * @return energy loss of the animal.
     */

    virtual int calculateEnergyLoss(Action *action);

    /**
     * @brief Function that executes the action chosen by the animal it handles all logic needed.
     * @param action - action to be executed
     */
    virtual void executeAction(Action *action);

    /**
     * @brief Function that checks if the animal is alive.
     * @return nullptr if animal is alive, ActionDie if animal is dead.
     * Function deletes action after updating animal with correct values.
     */

    virtual ~Animal();
};



#endif //ANIMAL_H
