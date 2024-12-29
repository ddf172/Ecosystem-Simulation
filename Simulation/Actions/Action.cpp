#include "Action.h"

Action::Action(ActionType type) {
    this->type = type;
}

ActionType Action::getType() {
    return this->type;
}