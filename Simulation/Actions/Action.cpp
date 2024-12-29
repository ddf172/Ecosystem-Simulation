#include "Action.h"

Action::Action(ActionType type) {
    this->type = type;
}

ActionType Action::getType() const {
    return this->type;
}