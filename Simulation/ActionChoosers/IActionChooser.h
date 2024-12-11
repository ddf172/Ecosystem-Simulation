//
// Created by jakub on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_IACTIONCHOOSER_H
#define ECOSYSTEM_SIMULATION_IACTIONCHOOSER_H

#include "../Actions/Action.h"
#include "../Animals/Animal.h"

class IActionChooser {
    public:
    virtual Action* chooseAction(Animal* animal) = 0;
    virtual ~IActionChooser() = default;
};


#endif //ECOSYSTEM_SIMULATION_IACTIONCHOOSER_H
