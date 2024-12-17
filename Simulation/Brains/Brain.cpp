//
// Created by ddf on 11.12.2024.
//

#include "Brain.h"

Brain::Brain(std::weak_ptr<Animal> animal) : animal(animal) {}

void Brain::addActionChooser(IActionChooser* actionChooser) {
    actionChoosers.emplace_back(actionChooser);
}

std::shared_ptr<Action> Brain::chooseAction() {
    for (const auto& actionChooser : actionChoosers) {
        std::shared_ptr<Action> action(actionChooser->chooseAction(animal));
        if (action != nullptr) {
            return action;
        }
    }
    return std::make_shared<ActionMove>(0, 0);
}

void Brain::clearActionChoosers() {
    actionChoosers.clear();
}

std::vector<std::shared_ptr<IActionChooser>>& Brain::getActionChoosers() {
    return actionChoosers;
}

Brain::~Brain(){
    actionChoosers.clear();
}