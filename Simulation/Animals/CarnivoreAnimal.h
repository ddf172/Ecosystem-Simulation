#ifndef ECOSYSTEM_SIMULATION_CARNIVOREANIMAL_H
#define ECOSYSTEM_SIMULATION_CARNIVOREANIMAL_H

#include "Animal.h"
#include "../ActionChoosers/AttackActionChoosers/AttackActionChooserDefault.h"
#include "../ActionChoosers/EatActionChoosers/EatActionChooserDefault.h"
#include "../ActionChoosers/MoveActionChoosers/MoveActionChooserNearestResourceTile.h"
#include "../ActionChoosers/ReproduceActionChoosers/ReproduceActionChooserSoloDefault.h"
#include "../ActionChoosers/DieActionChoosers/DieActionChooserDefault.h"


class CarnivoreAnimal : public Animal {
private:
    void initializeBrain() override;

public:
    CarnivoreAnimal(int id, int startX, int startY);

    CarnivoreAnimal(int id, int startX, int startY, int speed, int currentEnergy, int maxEnergy,
                    int sightRange, int strength, int maxEatAmount, int health, int maxHealth);

    std::shared_ptr<Action> chooseAction(std::vector<std::shared_ptr<Tile>> &surroundingTiles) override;

    ~CarnivoreAnimal();

};


#endif //ECOSYSTEM_SIMULATION_CARNIVOREANIMAL_H
