//
// Created by Piotrek on 09.12.2024.
//

#include "GraphicAnimal.h"
#include <random>
#include <iostream>

GraphicAnimal::GraphicAnimal(Animal *animal, sf::RenderWindow* window, float tileSize) {
    this->animal = animal;
    this->window = window;
    this->tileSize = tileSize;
    this->shape = sf::CircleShape(tileSize * 0.2f);

    switch (animal->getType()) {
        case HERBIVORE:
            this->shape.setFillColor(sf::Color::Yellow);
            break;
        case CARNIVORE:
            this->shape.setFillColor(sf::Color::Cyan);
            break;
        case OMNIVORE:
            this->shape.setFillColor(sf::Color::Magenta);
        break;
    }
    this->shape.setPosition(this->animal->getX(), this->animal->getY());
    this->window->draw(this->shape);
}

void GraphicAnimal::updatePosition() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 0.8f);

    float randomOffsetX = dist(gen) * tileSize;
    float randomOffsetY = dist(gen) * tileSize;
    this->shape.setPosition(this->animal->getX() * tileSize + randomOffsetX, this->animal->getY() * tileSize + randomOffsetY);

    this->window->draw(this->shape);
}

Animal *GraphicAnimal::getAnimal() {
    return this->animal;
}


