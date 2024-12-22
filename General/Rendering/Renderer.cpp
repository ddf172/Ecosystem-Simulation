//
// Created by Piotrek on 08.12.2024.
//

#include "Renderer.h"
#include <random>
#include <iostream>

#ifdef _WIN32
    #include <wtypes.h> // Windows-specific header
#elif defined(__linux__)
    #include <X11/Xlib.h> // Linux-specific header
#else
    #error "Unsupported platform"
#endif

void Renderer::initRender() {
    for (int i = 0; i < this->grid->getHeight(); i++) {
        for (int j = 0; j < this->grid->getWidth(); j++) {
            this->graphicTiles.push_back(GraphicTile(this->grid->getTile(j, i), this->window, this->tileSize));
        }
    }

    for (int i = 0; i < this->grid->getHeight(); i++) {
        for (int j = 0; j < this->grid->getWidth(); j++) {
            std::vector<std::shared_ptr<Animal>>* animalsOnTile = this->grid->getTile(j, i)->getAnimalsOnTile();
            for (std::shared_ptr<Animal> animal : *animalsOnTile) {
                graphicAnimals.push_back(GraphicAnimal(animal, this->window, this->tileSize));
            }
        }
    }
    this->window->display();
}

Renderer::Renderer(Grid *grid) {
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
        Screen* s = DefaultScreenOfDisplay(d);
        width = s->width * 0.8;
        height = s->height * 0.8;
        XCloseDisplay(d);
    #endif

    float maxTileHeight = height / grid->getHeight();
    float maxTileWidth = (width * 0.8) / grid->getWidth();
    this->tileSize = std::min(maxTileWidth, maxTileHeight);
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Ecosystem simulation", sf::Style::Titlebar | sf::Style::Close);
    this->grid = grid;
    initRender();
}

void Renderer::renderTurn() {
    window->clear(sf::Color::Black);

    for (auto it = graphicTiles.begin(); it != graphicTiles.end(); ) {
        if (it->getTile() == nullptr) {
            it = graphicTiles.erase(it);
        } else {
            it->updateFillColor();
            ++it;
        }
    }


    for(int i = 0; i < this->grid->getHeight(); i++) {
        for(int j = 0; j < this->grid->getWidth(); j++) {
            std::shared_ptr<Tile> tile = this->grid->getTile(j, i);
            for(std::shared_ptr<Animal> animal : *(tile->getAnimalsOnTile())) {
                sf::CircleShape shape = sf::CircleShape(tileSize * 0.2f);
                switch (animal->getType()) {
                    case HERBIVORE:
                        shape.setFillColor(sf::Color::Yellow);
                    break;
                    case CARNIVORE:
                        shape.setFillColor(sf::Color::Cyan);
                    break;
                    case OMNIVORE:
                        shape.setFillColor(sf::Color::Magenta);
                    break;
                }
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_real_distribution<float> dist(0.0f, 0.8f);

                float randomOffsetX = dist(gen) * tileSize;
                float randomOffsetY = dist(gen) * tileSize;
                shape.setPosition(animal->getX() * tileSize + randomOffsetX, animal->getY() * tileSize + randomOffsetY);
                this->window->draw(shape);
            }
        }
    }

    /*  version using graphic animals

    for (auto it = graphicAnimals.begin(); it != graphicAnimals.end(); ) {
        if (it->getAnimal() == nullptr || it->getAnimal()->getHealth() == 0) {
            it = graphicAnimals.erase(it);
        } else {
            it->updatePosition();
            ++it;
        }
    }
    */
    window->display();
}

sf::RenderWindow *Renderer::getWindow() {
    return this->window;
}

Renderer::~Renderer() {
    delete window;
}



