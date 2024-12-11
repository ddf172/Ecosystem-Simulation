//
// Created by ddf on 11.12.2024.
//

#include "Brain.h"

Brain::Brain(Animal* animal) : animal(animal) {}

void Brain::addActionChooser(IActionChooser* actionChooser) {
    actionChoosers.emplace_back(actionChooser);
}

std::unique_ptr<Action> Brain::chooseAction() {
    for (const auto& actionChooser : actionChoosers) {
        std::unique_ptr<Action> action(actionChooser->chooseAction(animal));
        if (action != nullptr) {
            return action;
        }
    }
    return std::make_unique<ActionMove>(0, 0);
}

void Brain::clearActionChoosers() {
    actionChoosers.clear();
}
