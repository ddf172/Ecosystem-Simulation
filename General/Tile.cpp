//
// Created by Piotrek on 29.10.2024.
//

#include "Tile.h"

void Tile::SetResourceOnTile(Resource* resource) {
    resourceOnTile = resource;
}

Resource* Tile::GetResourceOnTile() {
    return resourceOnTile;
}

Tile::Tile(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
    this->resourceOnTile = nullptr;
    this->animalsOnTile = std::vector<Animal*>();
}
