#ifndef ECOSYSTEM_SIMULATION_REPRODUCEACTIONCHOOSERSOLODEFAULT_H
#define ECOSYSTEM_SIMULATION_REPRODUCEACTIONCHOOSERSOLODEFAULT_H

#include "../IActionChooser.h"
#include "../../Actions/ActionReproduce.h"

class ReproduceActionChooserSoloDefault : public IActionChooser{
    std::shared_ptr<Tile> currentTile;
public:
    ReproduceActionChooserSoloDefault();
    std::shared_ptr<Action> chooseAction(Animal* animal) override;
    ~ReproduceActionChooserSoloDefault() override = default;
    void setCurrentTile(std::shared_ptr<Tile>& newCurrentTile);
};


#endif //ECOSYSTEM_SIMULATION_REPRODUCEACTIONCHOOSERSOLODEFAULT_H
