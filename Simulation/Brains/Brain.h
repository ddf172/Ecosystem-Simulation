//
// Created by ddf on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_BRAIN_H
#define ECOSYSTEM_SIMULATION_BRAIN_H

#include <memory>
#include <vector>
#include "../ActionChoosers/IActionChooser.h"

class Animal;
class IActionChooser;

class Brain {
private:
    std::vector<std::shared_ptr<IActionChooser>> actionChoosers;
    std::weak_ptr<Animal> animal;

public:
    explicit Brain(std::weak_ptr<Animal> animal);

    void addActionChooser(IActionChooser* actionChooser);

    std::shared_ptr<Action> chooseAction();

    void clearActionChoosers();

    std::vector<std::shared_ptr<IActionChooser>>& getActionChoosers();

    ~Brain();
};

#endif //ECOSYSTEM_SIMULATION_BRAIN_H