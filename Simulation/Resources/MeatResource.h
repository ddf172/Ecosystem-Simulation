#ifndef MEATRESOURCE_H
#define MEATRESOURCE_H
#include "Resource.h"


class MeatResource: public Resource  {
private:
    int decomposingRate;

public:
    MeatResource(int amount);
    MeatResource(int amount, int energyValue);
    void decompose();
    int getDecomposingRate();
    ~MeatResource() override = default;
};



#endif //MEATRESOURCE_H
