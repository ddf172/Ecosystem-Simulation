//
// Created by jakub on 17.11.2024.
//

#include "Action.h"

Action::Action(actionType type) {
    this->type = type;
}

actionType Action::getType() {
    return this->type;
}