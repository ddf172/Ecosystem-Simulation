//
// Created by Piotrek on 29.10.2024.
//

#ifndef MEATRESOURCE_H
#define MEATRESOURCE_H
#include "Resource.h"


class MeatResource: public Resource {
private:
    int amountLeft;
public:
    MeatResource(int energyValue, int amount);
    Resource* GetResource() override;
    ~MeatResource();
};



#endif //MEATRESOURCE_H
