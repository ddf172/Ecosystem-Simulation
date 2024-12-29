#include "ActionReproduce.h"

ActionReproduce::ActionReproduce(int offSpringNumber) : offSpringNumber(offSpringNumber), Action(ActionType::REPRODUCE) {}

int ActionReproduce::getOffSpringNumber() const {
    return this->offSpringNumber;
}