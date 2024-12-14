//
// Created by jakub on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_EATACTIONCHOOSERDEFAULT_H
#define ECOSYSTEM_SIMULATION_EATACTIONCHOOSERDEFAULT_H

#include <memory>
#include "../IActionChooser.h"
#include <cassert>

class Tile;

class EatActionChooserDefault : public IActionChooser {
private:
    Tile* currentTile;

public:
    explicit EatActionChooserDefault(Tile* currentTile);

    EatActionChooserDefault();

    Action* chooseAction(Animal* animal) override;

    ~EatActionChooserDefault() override = default;

    void setCurrentTile(Tile* newCurrentTile);
};


#endif //ECOSYSTEM_SIMULATION_EATACTIONCHOOSERDEFAULT_H
