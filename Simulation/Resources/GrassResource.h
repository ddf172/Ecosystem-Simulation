//
// Created by Piotrek on 29.10.2024.
//

#ifndef GRASSRESOURCE_H
#define GRASSRESOURCE_H
#include "Resource.h"


class GrassResource: public Resource {
private:
    int currentRegrowCooldown;
    int maxRegrowCooldown;
    int regrowAmount;

public:
    GrassResource(int amount, int energyValue, int regrowAmount, int regrowCooldown);
    ~GrassResource() override = default;
    int getCurrentRegrowCooldown() const;
    int getRegrowAmount() const;
    void setCurrentRegrowCooldown(int newRegrowCooldown);
    void setRegrowAmount(int regrowAmount);
    void regenerate();
};

#endif //GRASSRESOURCE_H
