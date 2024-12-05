//
// Created by Piotrek on 29.10.2024.
//

#include "SimulationManager.h"

#include <algorithm>
#include <iostream>


#include <SFML/Graphics.hpp>
#include "Simulation/Resources/GrassResource.h"

#ifdef _WIN32
    #include <wtypes.h> // Windows-specific header
#elif defined(__linux__)
    #include <X11/Xlib.h> // Linux-specific header
#else
    #error "Unsupported platform"
#endif

SimulationManager::SimulationManager(Grid *grid, int maxTurns, bool renderGame) {
    this->grid = grid;
    this->renderGame = renderGame;
    this->maxTurns = maxTurns;
}

sf::Color getTileColor(Tile* tile) {
    std::vector<Resource*>* resources = tile->getResourcesOnTile();
    if (resources->empty()) {
        return sf::Color::Black;
    }
    bool hasGrass = false;
    bool hasMeat = false;
    int alpha = 255;

    for(Resource* resource : *resources) {
        if (resource->getType() == GRASS) {
            hasGrass = true;
            alpha = ((float)resource->getAmount() / (float)resource->getMaxAmount()) * 255;
        }
        if (resource->getType() == MEAT) {
            hasMeat = true;
        }
    }

    if (hasGrass && hasMeat) return sf::Color(255, 192, 203);
    if (hasGrass) return sf::Color(0, 255, 0, alpha);
    if(hasMeat) return sf::Color::Red;
    return sf::Color::Black;
}

void SimulationManager::manageTurn() {
    // Manage resources
    for(int i = 0; i < grid->getHeight(); i++) {
        for(int j = 0; j < grid->getWidth(); j++) {
            Tile* tile = grid->getTile(j, i);
            std::vector<Resource*>* resources = tile->getResourcesOnTile();
            for(Resource* resource : *resources) {
                if(resource->getType() == GRASS) {
                    GrassResource* grass = dynamic_cast<GrassResource*>(resource);
                    grass->regenerate();
                }
            }
            // remove meat if there is no meat
            std::remove_if(resources->begin(), resources->end(), [](Resource* resource){ return resource->getType() == MEAT && resource->getAmount() <= 0;});
        }
    }

    // Manage animal actions
    for(int i = 0; i < grid->getHeight(); i++) {
        for(int j = 0; j < grid->getWidth(); j++) {
            Tile* tile = grid->getTile(j, i);
            std::vector<Animal*>* animals = tile->getAnimalsOnTile();
            for(Animal* animal : *animals) {
                std::vector<Tile*> surroundingTiles = grid->getSurroundingTiles(j, i, animal->getSightRange());
                Action* action = animal->chooseAction(surroundingTiles);

                if (action->getType() == MOVE) {
                    ActionMove* actionmove = dynamic_cast<ActionMove*>(action);
                    auto it = std::find(animals->begin(),animals->end(), animal);
                    animals->erase(it);
                    grid->getTile(actionmove->getX(), actionmove->getY())->addAnimalOnTile(animal);
                }
                else if (action-> getType() == EAT) {
                    ActionEat* actioneat = dynamic_cast<ActionEat*>(action);
                    for (Resource* resource : *tile->getResourcesOnTile()) {
                        if(resource->getType() == actioneat->getResourceType()) {
                            resource->setAmount(resource->getAmount() - actioneat->getAmount());
                        }
                    }
                }
                animal->executeAction(action);
            }
        }
    }
}

void SimulationManager::runSimulation() {
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

    sf::Clock clock;
    sf::Time renderInterval = sf::seconds(0.3f);
    sf::Time elapsedTime = sf::Time::Zero;

    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        elapsedTime = clock.getElapsedTime();
        if (elapsedTime >= renderInterval) {
            window.clear(sf::Color::Black);

            for (int i = 0; i < this->grid->getHeight(); i++) {
                for (int j = 0; j < this->grid->getWidth(); j++) {
                    sf::RectangleShape cell(sf::Vector2f(tileSize, tileSize));
                    cell.setPosition(j * tileSize, i * tileSize);
                    cell.setFillColor(getTileColor(this->grid->getTile(j, i)));
                    cell.setOutlineThickness(1);
                    cell.setOutlineColor(sf::Color(128, 128, 128));
                    window.draw(cell);

                    std::vector<Animal*>* animalsOnTile = this->grid->getTile(j, i)->getAnimalsOnTile();
                    bool herbFlag = false;
                    bool carnFlag = false;
                    bool omniFlag = false;
                    for (Animal* animal : *animalsOnTile) {
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
            clock.restart();
            manageTurn();
        }
    }
}

void SimulationManager::setRenderGame(bool val) {
    this->renderGame = val;
}

void SimulationManager::setMaxTurns(int val) {
    this->maxTurns = val;
}

