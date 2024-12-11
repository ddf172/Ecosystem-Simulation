//
// Created by Piotrek on 29.10.2024.
//

#include "SimulationManager.h"

#include <algorithm>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Rendering/Renderer.h"
#include "Simulation/Resources/GrassResource.h"
#include "Simulation/Resources/MeatResource.h"

SimulationManager::SimulationManager(Grid *grid) {
    this->grid = grid;
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
            std::vector<Animal*> toRemove;

            for(auto it = animals->begin(); it != animals->end();) {
                Animal* animal = *it;
                std::vector<Tile*> surroundingTiles = grid->getSurroundingTiles(j, i, animal->getSightRange());
                Action* action = animal->chooseAction(surroundingTiles);
                bool animalErased = false;

                animal->executeAction(action);

                if (action->getType() == MOVE) {
                    ActionMove* actionMove = dynamic_cast<ActionMove*>(action);
                    animals->erase(it);
                    animalErased = true;
                    grid->getTile(actionMove->getX(), actionMove->getY())->addAnimalOnTile(animal);
                }
                else if (action-> getType() == EAT) {
                    ActionEat* actionEat = dynamic_cast<ActionEat*>(action);
                    for (Resource* resource : *tile->getResourcesOnTile()) {
                        if(resource->getType() == actionEat->getResourceType()) {
                            resource->setAmount(resource->getAmount() - actionEat->getAmount());
                        }
                    }
                }
                else if (action-> getType() == DIE) {
                    ActionDie* actionDie = dynamic_cast<ActionDie*>(action);
                    auto it = std::find(animals->begin(),animals->end(), animal);
                    animals->erase(it);
                    animalErased = true;

                    tile->addResourceOnTile(new MeatResource(actionDie->getResourceAmount(), 3));

                    delete animal;

                }
                if (!animalErased) it++;
                delete action;
            }
        }
    }
}

void SimulationManager::runSimulation() {
    Renderer renderer(grid);
    sf::RenderWindow* window = renderer.getWindow();

    sf::Clock clock;
    sf::Time renderInterval = sf::seconds(0.3f);
    sf::Time elapsedTime = sf::Time::Zero;

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        elapsedTime = clock.getElapsedTime();
        if (elapsedTime >= renderInterval) {
            renderer.renderTurn();
            clock.restart();
            manageTurn();
        }
    }
}
