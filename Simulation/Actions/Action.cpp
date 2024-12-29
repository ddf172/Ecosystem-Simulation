//
// Created by jakub on 17.11.2024.
//

#include "Action.h"

Action::Action(ActionType type) {
    this->type = type;
}

ActionType Action::getType() const {
    return this->type;
}