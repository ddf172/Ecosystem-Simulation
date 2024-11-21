//
// Created by Piotrek on 29.10.2024.
//

#include "Tile.h"

#include <algorithm>
#include <iostream>

void Tile::setResourceOnTile(Resource* resource) {
    resourceOnTile = resource;
}

Resource* Tile::getResourceOnTile() {
    if (this->resourceOnTile == nullptr) {
        return nullptr;
    }
    ResourceType type = resourceOnTile->getType();
    if (type == EMPTY) {
        delete resourceOnTile;
        return nullptr;
    }
    return resourceOnTile;
}

Tile::Tile(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    this->resourceOnTile = nullptr;
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

std::vector<Animal *> Tile::getAnimalsOnTile() {
    return this->animalsOnTile;
}

int Tile::getX() const {
    return this->posX;
}

int Tile::getY() const {
    return this->posY;
}


