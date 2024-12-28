//
// Created by Piotrek on 11.12.2024.
//

#ifndef MEATRESOURCE_H
#define MEATRESOURCE_H
#include "Resource.h"


class MeatResource: public Resource  {

public:
    MeatResource(int amount);
    MeatResource(int amount, int energyValue);
    ~MeatResource() override = default;
};



#endif //MEATRESOURCE_H
