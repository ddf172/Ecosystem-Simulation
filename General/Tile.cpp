//
// Created by Piotrek on 29.10.2024.
//

#include "Tile.h"

#include <algorithm>
#include <iostream>

void Tile::addResourceOnTile(std::shared_ptr<Resource> resource) {
    this->resourcesOnTile += resource;
}

std::vector<std::shared_ptr<Resource>>* Tile::getResourcesOnTile() {
    return this->resourcesOnTile.getData();
}

Tile::Tile(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    this->resourcesOnTile = MergingContainer<std::shared_ptr<Resource>>();
    this->animalsOnTile = std::vector<std::shared_ptr<Animal>>();
}

void Tile::addAnimalOnTile(std::shared_ptr<Animal> animal) {
    this->animalsOnTile.push_back(animal);
}

void Tile::removeAnimalOnTile(std::shared_ptr<Animal> animal){
    auto it = std::find(this->animalsOnTile.begin(), this->animalsOnTile.end(), animal);
    if (it != this->animalsOnTile.end()) {
        this->animalsOnTile.erase(it);
    }
}

std::vector<std::shared_ptr<Animal>>* Tile::getAnimalsOnTile() {
    return &this->animalsOnTile;
}

int Tile::getX() const {
    return this->posX;
}

int Tile::getY() const {
    return this->posY;
}

Tile::~Tile() {
    this->resourcesOnTile.getData()->clear();
}



