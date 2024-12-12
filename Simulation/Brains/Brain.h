//
// Created by ddf on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_BRAIN_H
#define ECOSYSTEM_SIMULATION_BRAIN_H

#include <memory>
#include <vector>
#include "../ActionChoosers/IActionChooser.h"
#include "../Animals/Animal.h"

class Brain {
private:
    std::vector<std::shared_ptr<IActionChooser>> actionChoosers;
    Animal* animal;

public:
    explicit Brain(Animal* animal);

    void addActionChooser(IActionChooser* actionChooser);

    Action* chooseAction();

    void clearActionChoosers();

    ~Brain() = default;
};

#endif //ECOSYSTEM_SIMULATION_BRAIN_H
