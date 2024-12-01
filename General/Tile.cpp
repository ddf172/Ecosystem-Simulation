//
// Created by Piotrek on 29.10.2024.
//

#include "Tile.h"

#include <algorithm>
#include <iostream>

void Tile::addResourceOnTile(Resource* resource) {
    this->resourcesOnTile.push_back(resource);
}

std::vector<Resource*>* Tile::getResourcesOnTile() {
    return &this->resourcesOnTile;
}

Tile::Tile(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    this->resourcesOnTile = std::vector<Resource*>();
    this->animalsOnTile = std::vector<Animal*>();
}

void Tile::addAnimalOnTile(Animal *animal) {
    this->animalsOnTile.push_back(animal);
}

void Tile::removeAnimalOnTile(Animal *animal){
    auto it = std::find(this->animalsOnTile.begin(), this->animalsOnTile.end(), animal);
    if (it != this->animalsOnTile.end()) {
        this->animalsOnTile.erase(it);
    }
}

std::vector<Animal *>* Tile::getAnimalsOnTile() {
    return &this->animalsOnTile;
}

int Tile::getX() const {
    return this->posX;
}

int Tile::getY() const {
    return this->posY;
}

Tile::~Tile() {
    for(Resource* resource : this->resourcesOnTile) {
        delete resource;
    }
}



