//
// Created by ddf on 28.10.2024.
//

#include <Utilities/Renderer.h>
#include <random>

#include "Grid.h"
#include "Simulation/Animals/HerbivoreAnimal.h"

// Created purely to test rendering
int getRandomNumber() {
    std::random_device rd; // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister random number engine
    std::uniform_int_distribution<int> dist(0, 4); // Range: 0 to 4
    return dist(gen);
}

int main() {
    Grid* grid = new Grid(20, 20, Grid::RANDOM);
    Utilities::Renderer renderer = Utilities::Renderer(grid);

    // Random herbivoreAnimal spawn for testing
    for(int i = 0; i < grid->getHeight(); i++) {
        for(int j = 0; j < grid->getWidth(); j++) {
            int n = getRandomNumber();
            switch (n) {
                case 0:
                    grid->getTile(j, i)->addAnimalOnTile(new HerbivoreAnimal(0, j, i));
                    break;
            }
        }
    }
    renderer.renderGrid();
    delete grid;
    return 0;
}