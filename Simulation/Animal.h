//
// Created by Piotrek on 29.10.2024.
//
#ifndef ANIMAL_H
#define ANIMAL_H


class Animal {
// Current uncommented code is for testing until
// sensible solution to Animal code structure is implemented
private:
    // I think id will be useful
    int id;
    int posX;
    int posY;
    int speed;
    int currentEnergy;
    int maxEnergy;
    int sightRange;
public:
    Animal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange);
    int getX();
    int getY();
    /**
    *   Move to the destination coordinates
    */
    virtual void move(int desX, int desY);
    /**
     *  Animal eats resource on the current tile
     */
    virtual void eat();
    /**
    *  Animal breeds with animal on the current tile if possible
    */
    virtual void breed();
    /**
    *  Animal attacks other animal on the current tile if possible
    */
    virtual void attack();

    /**
     * @brief Function that calculates energy loss of the animal based on chosen action and statistics of the animal.
     * @return energy loss of the animal.
     */
    virtual int calculateEnergyLoss();
};



#endif //ANIMAL_H
