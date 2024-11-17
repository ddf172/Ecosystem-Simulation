//
// Created by Piotrek on 29.10.2024.
//

#include "Animal.h"

Animal::Animal(int id, int startX, int startY, int speed, int maxEnergy, int sightRange, int strength, AnimalType type) {
    this->id = id;
    this->posX = startX;
    this->posY = startY;
    this->currentEnergy = int(maxEnergy/2);
    this->maxEnergy = maxEnergy;
    this->speed = speed;
    this->sightRange = sightRange;
    this->strength = strength;
    this->type = type;
}

int Animal::getX() {
    return posX;
}

int Animal::getY() {
    return posY;
}

void Animal::move(int desX, int desY) {
    posX = desX;
    posY = desY;
}