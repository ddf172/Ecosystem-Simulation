//
// Created by Piotrek on 09.12.2024.
//

#ifndef GRAPHICTILE_H
#define GRAPHICTILE_H

#include "General/SimulationEngine/Tile.h"
#include <SFML/Graphics.hpp>
#include <memory>


class GraphicTile {
    std::shared_ptr<Tile> tile;
    sf::RectangleShape tileShape;
    sf::RenderWindow* window;
    sf::RectangleShape meatShape;
public:
    GraphicTile(const std::shared_ptr<Tile>& tile, sf::RenderWindow* window, float tileSize);
    void updateFillColor();
    std::shared_ptr<Tile> getTile();
};



#endif //GRAPHICTILE_H
