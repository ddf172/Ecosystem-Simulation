//
// Created by jakub on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_IACTIONCHOOSER_H
#define ECOSYSTEM_SIMULATION_IACTIONCHOOSER_H

#include "../Animals/Animal.h"

class Animal;

class IActionChooser {
    public:
    virtual std::shared_ptr<Action> chooseAction(Animal* animal) = 0;
    virtual ~IActionChooser() = default;
};


#endif //ECOSYSTEM_SIMULATION_IACTIONCHOOSER_H
