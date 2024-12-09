//
// Created by Piotrek on 09.12.2024.
//

#ifndef GRAPHICTILE_H
#define GRAPHICTILE_H

#include "General/Tile.h"
#include <SFML/Graphics.hpp>


class GraphicTile {
    Tile* tile;
    sf::RectangleShape shape;
    sf::RenderWindow* window;
public:
    GraphicTile(Tile* tile, sf::RenderWindow* window, float tileSize);
    void updateFillColor();
    Tile* getTile();
};



#endif //GRAPHICTILE_H
