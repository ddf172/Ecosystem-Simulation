#ifndef ECOSYSTEM_SIMULATION_ACTIONATTACK_H
#define ECOSYSTEM_SIMULATION_ACTIONATTACK_H

#include "ActionMove.h"
#include "Simulation/Animals/Animal.h"
#include <memory>

class Animal;

class ActionAttack : public ActionMove{
private:
    int damage;
    std::shared_ptr<Animal> targetAnimal;

public:
    ActionAttack(int x, int y, int damage, std::shared_ptr<Animal> targetAnimal);
    int getDamage() const;
    std::shared_ptr<Animal> getTargetAnimal() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONATTACK_H
