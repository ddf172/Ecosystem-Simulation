#ifndef ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H
#define ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H

#include "../IActionChooser.h"
#include <cassert>
#include "../../Actions/ActionAttack.h"
#include <memory>
#include "Utilities/Utilities.h"

class AttackActionChooserDefault : public IActionChooser{
private:
    std::vector<std::shared_ptr<Tile>> targetTiles;

public:
    AttackActionChooserDefault();
    std::shared_ptr<Action> chooseAction(Animal* animal) override;
    void setTargetTiles(std::vector<std::shared_ptr<Tile>> newTargetTiles);
};


#endif //ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H
