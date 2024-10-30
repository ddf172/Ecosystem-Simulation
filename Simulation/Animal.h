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
    int GetX();
    int GetY();
    /**
    *   Move to the destination coordinates
    */
    virtual void Move(int desX, int desY);
    /**
     *  Animal eats resource on the current tile
     */
    virtual void Eat();
    /**
    *  Animal breeds with animal on the current tile if possible
    */
    virtual void Breed();
    /**
    *  Animal attacks other animal on the current tile if possible
    */
    virtual void Attack();
};



#endif //ANIMAL_H
