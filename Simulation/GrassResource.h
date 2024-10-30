//
// Created by Piotrek on 29.10.2024.
//

#ifndef GRASSRESOURCE_H
#define GRASSRESOURCE_H
#include "Resource.h"


class GrassResource: public Resource {
private:
    // If currentRegrowTime == maxRegrowTime then grass is ready to be eaten
    int currentRegrowTime;
    int maxRegrowTime;
public:
    GrassResource(int energyValue, int maxRegrowTime);
    ~GrassResource();
};



#endif //GRASSRESOURCE_H
