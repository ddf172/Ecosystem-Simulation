//
// Created by Piotrek on 29.10.2024.
//

#ifndef GRASSRESOURCE_H
#define GRASSRESOURCE_H
#include "Resource.h"


class GrassResource: public Resource {
private:
    // If currentRegrowCooldown == 0 then grass is ready to be eaten
    int currentRegrowCooldown;
    int maxRegrowCooldown;
public:
    void decrementRegrowCooldown();
    int eatResource() override;
    GrassResource(int energyValue, int maxRegrowCooldown);
    ~GrassResource();
};

#endif //GRASSRESOURCE_H
