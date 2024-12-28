//
// Created by Piotrek on 08.12.2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <random>
#include "GraphicTile.h"
#include "General/SimulationEngine/Grid.h"

class Renderer {
    sf::RenderWindow* window;
    Grid* grid;
    std::vector<GraphicTile> graphicTiles;
    float tileSize;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dist;
    void initRender();
    void renderAnimals();
    void renderTiles();
public:
    Renderer(Grid *grid);
    void renderTurn();
    sf::RenderWindow* getWindow();
    ~Renderer();
};



#endif //RENDERER_H
