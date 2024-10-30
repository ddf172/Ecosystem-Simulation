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
    void AddAnimalOnTile(Animal* animal);
    void RemoveAnimalOnTile(Animal* animal);
    Resource* GetResourceOnTile();
    void SetResourceOnTile(Resource* resource);
    int GetPosX();
    int GetPosY();
};

#endif //TILE_H
