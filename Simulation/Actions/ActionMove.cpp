//
// Created by jakub on 17.11.2024.
//

#include "ActionMove.h"

ActionMove::ActionMove(int x, int y) : Action(MOVE) {
    this->x = x;
    this->y = y;
}

int ActionMove::getX() const {
    return this->x;
}

int ActionMove::getY() const {
    return this->y;
}