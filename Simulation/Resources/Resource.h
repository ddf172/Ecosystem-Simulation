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
    virtual ~Resource() = default;
    virtual int eatResource() = 0;
    ResourceType getType();
};

#endif //RESOURCE_H
