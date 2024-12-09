//
// Created by Piotrek on 08.12.2024.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

#include "GraphicAnimal.h"
#include "GraphicTile.h"
#include "General/Grid.h"

class Renderer {
    sf::RenderWindow* window;
    Grid* grid;
    std::vector<GraphicAnimal> graphicAnimals;
    std::vector<GraphicTile> graphicTiles;
    float tileSize;
    void initRender();
    sf::Color getTileColor(Tile* tile);
public:
    Renderer(Grid *grid);
    void renderTurn();
    sf::RenderWindow* getWindow();
};



#endif //RENDERER_H
