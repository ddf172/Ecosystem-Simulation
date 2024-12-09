//
// Created by Piotrek on 09.12.2024.
//

#ifndef GRAPHICANIMAL_H
#define GRAPHICANIMAL_H
#include "Simulation/Animals/Animal.h"
#include <SFML/Graphics.hpp>


class GraphicAnimal {
    Animal* animal;
    sf::CircleShape shape;
    sf::RenderWindow* window;
    float tileSize;
public:
    GraphicAnimal(Animal* animal, sf::RenderWindow* window, float tileSize);
    void updatePosition();
    Animal* getAnimal();
};



#endif //GRAPHICANIMAL_H
