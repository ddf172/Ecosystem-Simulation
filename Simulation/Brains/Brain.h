#ifndef ECOSYSTEM_SIMULATION_BRAIN_H
#define ECOSYSTEM_SIMULATION_BRAIN_H

#include <memory>
#include <vector>
#include "../ActionChoosers/IActionChooser.h"

class Animal;
class IActionChooser;

class Brain {
private:
    std::vector<std::shared_ptr<IActionChooser>> actionChoosers;
    Animal* animal;

public:
    explicit Brain(Animal* animal);

    void addActionChooser(IActionChooser* actionChooser);

    std::shared_ptr<Action> chooseAction();

    void clearActionChoosers();

    std::vector<std::shared_ptr<IActionChooser>>& getActionChoosers();

    ~Brain();
};

#endif //ECOSYSTEM_SIMULATION_BRAIN_H