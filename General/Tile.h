//
// Created by Piotrek on 29.10.2024.
//

#ifndef TILE_H
#define TILE_H
#include <vector>
#include "Simulation/Animal.h"
#include "Simulation/Resource.h"


class Tile {
private:
    int posX;
    int posY;
    std::vector<Animal*> animalsOnTile;
    Resource* resourceOnTile;
public:
    Tile(int posX, int posY);
    std::vector<Animal*> getAnimalsOnTile();
    void addAnimalOnTile(Animal* animal);
    void removeAnimalOnTile(Animal* animal);
    Resource* getResourceOnTile();
    void setResourceOnTile(Resource* resource);
    int getPosX();
    int getPosY();
};

#endif //TILE_H
