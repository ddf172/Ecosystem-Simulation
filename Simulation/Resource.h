//
// Created by Piotrek on 29.10.2024.
//

#ifndef RESOURCE_H
#define RESOURCE_H
#include "ResourceTypeEnum.h"

class Resource {
protected:
    ResourceType type;
    int energyValue;
public:
    void TakeResource();
    ResourceType GetType() {
        return type;
    }
};

#endif //RESOURCE_H
