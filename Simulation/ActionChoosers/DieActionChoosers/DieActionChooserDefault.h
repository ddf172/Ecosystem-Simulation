//
// Created by ddf on 11.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_DIEACTIONCHOOSERDEFAULT_H
#define ECOSYSTEM_SIMULATION_DIEACTIONCHOOSERDEFAULT_H

#include "../IActionChooser.h"

class DieActionChooserDefault : public IActionChooser {
public:
    std::shared_ptr<Action> chooseAction(std::weak_ptr<Animal> animal) override;
    ~DieActionChooserDefault() override = default;
};


#endif //ECOSYSTEM_SIMULATION_DIEACTIONCHOOSERDEFAULT_H
