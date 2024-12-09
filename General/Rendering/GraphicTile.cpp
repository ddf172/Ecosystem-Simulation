//
// Created by Piotrek on 09.12.2024.
//

#include "GraphicTile.h"
GraphicTile::GraphicTile(Tile *tile, sf::RenderWindow *window, float tileSize) {
    this->tile = tile;
    this->window = window;
    this->shape = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
    this->shape.setPosition(tile->getX() * tileSize, tile->getY() * tileSize);

    sf::Color fillColor = sf::Color::Black;
    for(Resource* resource : *(tile->getResourcesOnTile())) {
        if (resource->getType() == GRASS) {
            fillColor = sf::Color::Green;
        }
    }

    this->shape.setFillColor(fillColor);
    this->shape.setOutlineThickness(1);
    this->shape.setOutlineColor(sf::Color(128, 128, 128));
    this->window->draw(this->shape);
}

void GraphicTile::updateFillColor() {
    int alpha = 255;
    for(Resource* resource : *(tile->getResourcesOnTile())) {
        if (resource->getType() == GRASS) {
            alpha = ((float)resource->getAmount() / (float)resource->getMaxAmount()) * 255;
            break;
        }
    }
    sf::Color newColor = sf::Color(this->shape.getFillColor().r, this->shape.getFillColor().g, this->shape.getFillColor().b, alpha);
    this->shape.setFillColor(newColor);
    this->window->draw(this->shape);
}

Tile *GraphicTile::getTile() {
    return  this->tile;
}
