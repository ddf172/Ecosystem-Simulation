#ifndef ECOSYSTEM_SIMULATION_DIEACTIONCHOOSERDEFAULT_H
#define ECOSYSTEM_SIMULATION_DIEACTIONCHOOSERDEFAULT_H

#include "../IActionChooser.h"

class DieActionChooserDefault : public IActionChooser {
public:
    std::shared_ptr<Action> chooseAction(Animal* animal) override;
    ~DieActionChooserDefault() override = default;
};


#endif //ECOSYSTEM_SIMULATION_DIEACTIONCHOOSERDEFAULT_H
