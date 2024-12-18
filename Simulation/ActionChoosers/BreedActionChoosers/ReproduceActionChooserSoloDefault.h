//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_REPRODUCEACTIONCHOOSERSOLODEFAULT_H
#define ECOSYSTEM_SIMULATION_REPRODUCEACTIONCHOOSERSOLODEFAULT_H

#include "../IActionChooser.h"
#include "../../Actions/ActionReproduce.h"

class BreedActionChooserSoloDefault : public IActionChooser{
    std::shared_ptr<Tile> currentTile;
public:
    std::shared_ptr<Action> chooseAction(Animal* animal) override;
    ~BreedActionChooserSoloDefault() override = default;
};


#endif //ECOSYSTEM_SIMULATION_REPRODUCEACTIONCHOOSERSOLODEFAULT_H
