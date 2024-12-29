#ifndef TILE_H
#define TILE_H
#include <vector>
#include "Simulation/Animals/Animal.h"
#include "Simulation/Resources/Resource.h"
#include "Utilities/MergingContainer.h"

class Animal;

class Tile {
private:
    int posX;
    int posY;
    std::vector<std::shared_ptr<Animal>> animalsOnTile;
    MergingContainer<std::shared_ptr<Resource>> resourcesOnTile;
public:
    Tile(int posX, int posY);
    std::vector<std::shared_ptr<Animal>>* getAnimalsOnTile();
    void addAnimalOnTile(std::shared_ptr<Animal> animal);
    void removeAnimalOnTile(std::shared_ptr<Animal> animal);
    std::vector<std::shared_ptr<Resource>>* getResourcesOnTile();
    void addResourceOnTile(std::shared_ptr<Resource> resource);
    int getX() const;
    int getY() const;
    ~Tile();
};

#endif //TILE_H
