//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H
#define ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H

#include "../IActionChooser.h"

class AttackActionChooserDefault : IActionChooser{
private:
    std::shared_ptr<Tile> currentTile;

public:
    AttackActionChooserDefault();
    std::shared_ptr<Action> chooseAction(Animal* animal) override;
    void setCurrentTile(std::shared_ptr<Tile>& tile);
};


#endif //ECOSYSTEM_SIMULATION_ATTACKACTIONCHOOSERDEFAULT_H
