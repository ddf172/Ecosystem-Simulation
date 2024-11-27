//
// Created by Piotrek on 29.10.2024.
//

#include "Renderer.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "General/Grid.h"

#ifdef _WIN32
    #include <wtypes.h> // Windows-specific header
#elif defined(__linux__)
    #include <X11/Xlib.h> // Linux-specific header
#else
    #error "Unsupported platform"
#endif

using namespace Utilities;

Renderer::Renderer(Grid *grid) {
    this->grid = grid;
}


void Renderer::renderTestCircle() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

sf::Color getTileColor(Tile* tile) {
    std::vector<Resource*> resources = tile->getResourcesOnTile();
    if (resources.empty()) {
        return sf::Color::Black;
    }
    bool hasGrass = false;
    bool hasMeat = false;
    for(Resource* resource : resources) {
        if (resource->getType() == GRASS) {
            hasGrass = true;
        }
        if (resource->getType() == MEAT) {
            hasMeat = true;
        }
    }

    if (hasGrass && hasMeat) return sf::Color(255, 192, 203);
    if (hasGrass) return sf::Color::Green;
    if(hasMeat) return sf::Color::Red;
    return sf::Color::Black;
}


void Renderer::renderGrid() {

    float width = 0;
    float height = 0;

    #ifdef _WIN32
        HWND desktop = GetDesktopWindow();
        RECT desktopRect;
        GetWindowRect(desktop, &desktopRect);

        height = desktopRect.bottom * 0.8;
        width = desktopRect.right * 0.8;
    #elif defined(__linux__)
        Display* d = XOpenDisplay(NULL);
        Screen*  s = DefaultScreenOfDisplay(d);
        width = s->width;
        height = s->height;
    #endif

    float maxTileHeight = height / this->grid->getHeight();
    float maxTileWidth = (width * 0.8) / this->grid->getWidth();
    float tileSize = std::min(maxTileWidth, maxTileHeight);

    sf::RenderWindow window(sf::VideoMode(width, height), "Ecosystem simulation", sf::Style::Titlebar | sf::Style::Close);

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        for (int i = 0; i < this->grid->getHeight(); i++) {
            for (int j = 0; j < this->grid->getWidth(); j++) {
                sf::RectangleShape cell(sf::Vector2f(tileSize, tileSize));
                cell.setPosition(j * tileSize, i * tileSize);
                cell.setFillColor(getTileColor(this->grid->getTile(j, i)));
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color(128, 128, 128));
                window.draw(cell);

                std::vector<Animal*> animalsOnTile = this->grid->getTile(j, i)->getAnimalsOnTile();
                bool herbFlag = false;
                bool carnFlag = false;
                bool omniFlag = false;
                for (Animal* animal : animalsOnTile) {
                    if (animal->getType() == HERBIVORE) herbFlag = true;
                    else if (animal->getType() == CARNIVORE) carnFlag = true;
                    else if (animal->getType() == OMNIVORE) omniFlag = true;

                }

                if (herbFlag) {
                    sf::CircleShape circle(tileSize * 0.2f);
                    circle.setFillColor(sf::Color::Yellow);
                    circle.setPosition(j * tileSize + tileSize * 0.3f, i * tileSize + tileSize * 0.05f);
                    window.draw(circle);

                }
                if (carnFlag) {
                    sf::CircleShape circle(tileSize * 0.2f);
                    circle.setFillColor(sf::Color::Cyan);
                    circle.setPosition(j * tileSize + tileSize * 0.05f, i * tileSize + tileSize * 0.55f);
                    window.draw(circle);

                }
                if (omniFlag) {
                    sf::CircleShape circle(tileSize * 0.2f);
                    circle.setFillColor(sf::Color::Magenta);
                    circle.setPosition(j * tileSize + tileSize * 0.55f, i * tileSize + tileSize * 0.55f);
                    window.draw(circle);
                }

            }
        }

        window.display();
    }
}
