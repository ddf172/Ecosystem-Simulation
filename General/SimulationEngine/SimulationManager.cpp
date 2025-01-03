#include "General/SimulationEngine/SimulationManager.h"

#include <algorithm>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include "General/Rendering/Renderer.h"
#include "Utilities/StatisticsManager.h"
#include "Utilities/FileHandling/SettingsCSVReader.h"
#include "Simulation/Actions/ActionAttack.h"
#include "Simulation/Animals/CarnivoreAnimal.h"
#include "Simulation/Animals/HerbivoreAnimal.h"
#include "Simulation/Resources/GrassResource.h"
#include "Simulation/Resources/MeatResource.h"

SimulationManager::SimulationManager(Grid *grid) {
    this->grid = grid;
    this->renderGame = SettingsCSVReader::getInstance()->readSettings("SimulationManager", "renderGame") == "true";
    this->maxTurns = std::stoi(SettingsCSVReader::getInstance()->readSettings("SimulationManager", "maxTurns"));
}

void SimulationManager::updateTiles() {
    for(int i = 0; i < grid->getHeight(); i++) {
        for(int j = 0; j < grid->getWidth(); j++) {
            std::shared_ptr<Tile> tile = grid->getTile(j, i);
            std::vector<std::shared_ptr<Resource>>* resources = tile->getResourcesOnTile();
            for(std::shared_ptr<Resource> resource : *resources) {
                if(resource->getType() == GRASS) {
                    std::shared_ptr<GrassResource> grass = std::dynamic_pointer_cast<GrassResource>(resource);
                    grass->regenerate();
                }
                if(resource->getType() == MEAT) {
                    std::shared_ptr<MeatResource> meat = std::dynamic_pointer_cast<MeatResource>(resource);
                    meat->decompose();
                }
            }
        }
    }
}


void SimulationManager::manageTurn() {
    std::shared_ptr<StatisticsManager> stats = StatisticsManager::getInstance();
    stats->incrementTurn();

    updateTiles();

    // Manage animal actions
    for(int i = 0; i < grid->getHeight(); i++) {
        for(int j = 0; j < grid->getWidth(); j++) {
            std::shared_ptr<Tile> tile = grid->getTile(j, i);
            std::vector<std::shared_ptr<Animal>>* animals = tile->getAnimalsOnTile();
            std::vector<std::shared_ptr<Animal>> animalsToAdd;

            for(auto it = animals->begin(); it != animals->end();) {
                std::shared_ptr<Animal> animal = *it;
                std::vector<std::shared_ptr<Tile>> surroundingTiles = grid->getSurroundingTiles(j, i, animal->getSightRange());

                std::shared_ptr<Action> action = animal->chooseAction(surroundingTiles);
                bool animalErased = false;

                animal->executeAction(action);

                if (action->getType() == MOVE) {
                    auto* actionMove = dynamic_cast<ActionMove*>(action.get());
                    animals->erase(it);
                    animalErased = true;
                    grid->getTile(actionMove->getX(), actionMove->getY())->addAnimalOnTile(animal);

                } else if (action->getType() == EAT) {
                    auto* actionEat = dynamic_cast<ActionEat*>(action.get());
                    for (std::shared_ptr<Resource> resource : *tile->getResourcesOnTile()) {
                        if (resource->getType() == actionEat->getResourceType()) {
                            resource->setAmount(resource->getAmount() - actionEat->getAmount());
                        }
                    }

                } else if (action->getType() == DIE) {
                    std::string animalTypeStr;
                    switch(animal->getType()) {
                        case AnimalType::CARNIVORE:
                            animalTypeStr = "carnivore";
                            break;
                        case AnimalType::HERBIVORE:
                            animalTypeStr = "herbivore";
                            break;
                    }
                    stats->recordDeath(animalTypeStr);
                    auto* actionDie = dynamic_cast<ActionDie*>(action.get());
                    animals->erase(it);
                    animalErased = true;
                    tile->addResourceOnTile(std::make_shared<MeatResource>(actionDie->getResourceAmount()));

                } else if (action->getType() == REPRODUCE) {
                    std::string animalTypeStr;
                    switch(animal->getType()) {
                        case AnimalType::CARNIVORE:
                            animalTypeStr = "carnivore";
                            break;
                        case AnimalType::HERBIVORE:
                            animalTypeStr = "herbivore";
                            break;
                    }
                    stats->recordBirth(animalTypeStr);
                    auto* actionReproduce = dynamic_cast<ActionReproduce*>(action.get());
                    for(int k = 0; k < actionReproduce->getOffSpringNumber(); k++) {
                        if (animal->getType() == HERBIVORE) {
                            animalsToAdd.push_back(std::make_shared<HerbivoreAnimal>(0, j, i));
                        } else if (animal->getType() == CARNIVORE) {
                            animalsToAdd.push_back(std::make_shared<CarnivoreAnimal>(0, j, i));
                        }
                    }
                } else if (action->getType() == ATTACK) {
                    auto* actionAttack = dynamic_cast<ActionAttack*>(action.get());
                    actionAttack->getTargetAnimal()->setHealth(actionAttack->getTargetAnimal()->getHealth() - actionAttack->getDamage());
                }
                if (!animalErased) it++;
            }
            for(auto toAdd : animalsToAdd) {
                animals->push_back(toAdd);
            }
        }
    }

}

void SimulationManager::runSimulation() {
    int currentTurn = 0;
    if (renderGame) {
        Renderer renderer(grid);
        sf::RenderWindow* window = renderer.getWindow();

        sf::Clock clock;
        sf::Time renderInterval = sf::seconds(std::stof(SettingsCSVReader::getInstance()->readSettings("Clock", "intervals")));
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
                currentTurn++;
                if (currentTurn == this->maxTurns) {
                    window->close();
                }
            }
        }
    }
    else {
        while (currentTurn < maxTurns) {
            currentTurn++;
            std::cout << "Turn " << currentTurn << '\n';
            manageTurn();
        }
    }
    std::shared_ptr<StatisticsManager> stats = StatisticsManager::getInstance();
    stats->saveToFile();
}
