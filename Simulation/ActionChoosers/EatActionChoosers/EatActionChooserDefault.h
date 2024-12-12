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


    explicit EatActionChooserDefault(Tile* currentTile);

    EatActionChooserDefault();

    Action* chooseAction(Animal* animal) override;

    ~EatActionChooserDefault() override = default;
};


#endif //ECOSYSTEM_SIMULATION_EATACTIONCHOOSERDEFAULT_H
