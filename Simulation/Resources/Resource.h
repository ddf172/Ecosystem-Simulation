//
// Created by Piotrek on 29.10.2024.
//

#ifndef RESOURCE_H
#define RESOURCE_H
#include "ResourceTypeEnum.h"

class Resource {
protected:
    ResourceType type;
    int amount;
    // increase in energy value that the single amount gives
    int energyValue;
public:
    Resource(ResourceType type, int amount, int energyValue);
    virtual ~Resource() = default;
    ResourceType getType();
    int getAmount() const;
    int getEnergyValue() const;
    void setAmount(int amount);
    void setEnergyValue(int energyValue);
};

#endif //RESOURCE_H