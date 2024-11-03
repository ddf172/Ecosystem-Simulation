//
// Created by Piotrek on 03.11.2024.
//

#ifndef ENVIRONMENTHANDLER_H
#define ENVIRONMENTHANDLER_H
#include "Grid.h"


/**
 *  Class that is a middleman between animals and grid to ensure that Animals don't have access to unecessary functions.
 */
class EnvironmentHandler {
private:
 Grid* grid;
public:
 EnvironmentHandler(Grid* grid);
 std::vector<Tile> getSurroundingTiles(int centerX, int centerY, int range);
};



#endif //ENVIRONMENTHANDLER_H
