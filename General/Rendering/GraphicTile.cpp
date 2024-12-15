//
// Created by Piotrek on 09.12.2024.
//

#include "GraphicTile.h"
GraphicTile::GraphicTile(std::shared_ptr<Tile> tile, sf::RenderWindow *window, float tileSize) {
    this->tile = tile;
    this->window = window;
    this->tileShape = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
    this->tileShape.setPosition(tile->getX() * tileSize, tile->getY() * tileSize);

    this->meatShape = sf::RectangleShape(sf::Vector2f(tileSize * 0.5f, tileSize * 0.5f));
    this->meatShape.setPosition(tile->getX() * tileSize + (tileSize * 0.25f), tile->getY() * tileSize + (tileSize * 0.25f));
    this->meatShape.setFillColor(sf::Color::Transparent);

    sf::Color fillColor = sf::Color::Black;

    for(Resource* resource : *(tile->getResourcesOnTile())) {

        if (resource->getType() == GRASS) {
            fillColor = sf::Color::Green;

        } else if (resource->getType() == MEAT) {
            this->meatShape.setFillColor(sf::Color::Red);
        }
    }

    this->tileShape.setFillColor(fillColor);
    this->tileShape.setOutlineThickness(1);
    this->tileShape.setOutlineColor(sf::Color(128, 128, 128));

    this->window->draw(this->tileShape);
    this->window->draw(this->meatShape);
}

void GraphicTile::updateFillColor() {
    sf::Color grassColor = this->tileShape.getFillColor();
    sf::Color meatColor = this->meatShape.getFillColor();

    for (Resource* resource : *(tile->getResourcesOnTile())) {

        if (resource->getType() == GRASS) {
            int alpha = ((float)resource->getAmount() / (float)resource->getMaxAmount()) * 255;
            grassColor.a = std::clamp(alpha, 0, 255);

        } else if (resource->getType() == MEAT) {
            int alpha = ((float)resource->getAmount() / (float)100) * 255;
            meatColor = sf::Color::Red;
            meatColor.a = std::clamp(alpha, 0, 255);
        }
    }

    this->tileShape.setFillColor(grassColor);
    this->meatShape.setFillColor(meatColor);

    this->window->draw(this->tileShape);
    this->window->draw(this->meatShape);
}

std::shared_ptr<Tile> GraphicTile::getTile() {
    return  this->tile;
}
