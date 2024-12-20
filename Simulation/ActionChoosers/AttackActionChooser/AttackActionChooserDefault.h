//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H
#define ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H

#include "../IActionChooser.h"
#include <cassert>
#include "../../Actions/ActionAttack.h"
#include <memory>
#include "Utilities/Utilities.h"

class AttackActionChooserDefault : IActionChooser{
private:
    std::vector<std::shared_ptr<Tile>>* targetTiles;

public:
    AttackActionChooserDefault();
    std::shared_ptr<Action> chooseAction(Animal* animal) override;
    void setTargetTiles(std::vector<std::shared_ptr<Tile>>* targetTiles);
};


#endif //ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H
