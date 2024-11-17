//
// Created by Piotrek on 29.10.2024.
//
#ifndef ANIMAL_H
#define ANIMAL_H


#include <vector>
#include "General/Tile.h"

class Tile;

class Animal {
// Current uncommented code is for testing until
// sensible solution to Animal code structure is implemented
protected:
    enum AnimalType {
        HERBIVORE,
        CARNIVORE,
        OMNIVORE
    };
    // I think id will be useful
    int id;
    int posX;
    int posY;
    int speed;
    int currentEnergy;
    int maxEnergy;
    int sightRange;
    int strength;
    AnimalType type;
public:
    Animal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength, AnimalType type);
    int getX();
    int getY();

    /* COMMENT FROM PIT: Mysle ze bedzie git, jezeli zrobimy ten pomysl ze kazdy animal ma 2 dostepne akcje
     * i teraz -> move() - moze byc tylko w pierwszej akcji
     * eat() -> moze byc tylko w pierwszej akcji i druga wtedy przemija (ze jedzenie zajmuje cala ture)
     * attack() -> moze byc w pierwszej i drugiej, np. najpierw move potem attack
     * breed() -> moze byc w pierwszej i drugiej np. najpierw move potem breed
     */
    virtual void chooseAction(std::vector<Tile*>) = 0;
    /**
    *   Move to the destination coordinates
    */
    virtual void move(int desX, int desY);
    /**
     *  Animal eats resource on the current tile
     */
    // virtual void eat();
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
    // virtual int calculateEnergyLoss();
};



#endif //ANIMAL_H
