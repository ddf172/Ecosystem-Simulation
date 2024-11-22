//
// Created by Piotrek on 29.10.2024.
//

#ifndef TILE_H
#define TILE_H
#include <vector>
#include "Simulation/Animals/Animal.h"
#include "Simulation/Resources/Resource.h"

class Animal;

class Tile {
private:
    int posX;
    int posY;
    std::vector<Animal*> animalsOnTile;
    std::vector<Resource*> resourcesOnTile;
public:
    Tile(int posX, int posY);
    std::vector<Animal*> getAnimalsOnTile();
    void addAnimalOnTile(Animal* animal);
    void removeAnimalOnTile(Animal* animal);
    std::vector<Resource*> getResourcesOnTile();
    void addResourceOnTile(Resource* resource);
    int getX() const;
    int getY() const;
};

#endif //TILE_H
