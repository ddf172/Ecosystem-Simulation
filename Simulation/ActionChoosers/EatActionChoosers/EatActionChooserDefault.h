//
// Created by jakub on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_EATACTIONCHOOSERDEFAULT_H
#define ECOSYSTEM_SIMULATION_EATACTIONCHOOSERDEFAULT_H

#include "../IActionChooser.h"

class EatActionChooserDefault : public IActionChooser {
private:
    Tile* currentTile;

public:
    EatActionChooserDefault(Tile* currentTile);

    Action* chooseAction(Animal* animal) override;

    ~EatActionChooserDefault() override = default;
};


#endif //ECOSYSTEM_SIMULATION_EATACTIONCHOOSERDEFAULT_H
