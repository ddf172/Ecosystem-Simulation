//
// Created by Piotrek on 29.10.2024.
//

#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include "wtypes.h"
#include "General/Grid.h"

using namespace Utilities;

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

void Renderer::renderGrid(Grid& grid) {
    HWND desktop = GetDesktopWindow();
    RECT desktopRect;
    GetWindowRect(desktop, &desktopRect);

    float height = desktopRect.bottom * 0.8;
    float width = desktopRect.right * 0.8;

    float maxTileHeight = height / grid.getHeight();
    float maxTileWidth = (width * 0.8) / grid.getWidth();
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

        for (int i = 0; i < grid.getHeight(); i++) {
            for (int j = 0; j < grid.getWidth(); j++) {
                sf::RectangleShape cell(sf::Vector2f(tileSize, tileSize));
                cell.setPosition(j * tileSize, i * tileSize);
                cell.setFillColor(sf::Color::Black);
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color(128, 128, 128));

                window.draw(cell);
            }
        }

        window.display();
    }
}
