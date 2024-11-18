//
// Created by Piotrek on 29.10.2024.
//

#ifndef GRASSRESOURCE_H
#define GRASSRESOURCE_H
#include "Resource.h"


class GrassResource: public Resource {
private:
    int regrowCooldown;
    int regrowAmount;
public:
    GrassResource(int amount, int energyValue, int regrowAmount, int regrowCooldown);
    ~GrassResource();
};

#endif //GRASSRESOURCE_H
