//
// Created by ddf on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_BRAIN_H
#define ECOSYSTEM_SIMULATION_BRAIN_H

#include <vector>
#include <memory>
#include "../ActionChoosers/IActionChooser.h"
#include "../Actions/Action.h"
#include "../Actions/ActionMove.h"

class IActionChooser;

class Animal;

class Brain {
private:
    std::vector<std::shared_ptr<IActionChooser>> actionChoosers;
    Animal* animal;

public:
    explicit Brain(Animal* animal);

    void addActionChooser(IActionChooser* actionChooser);

    Action* chooseAction();

    void clearActionChoosers();

    std::vector<std::shared_ptr<IActionChooser>>& getActionChoosers();

    ~Brain() = default;
};

#endif //ECOSYSTEM_SIMULATION_BRAIN_H
