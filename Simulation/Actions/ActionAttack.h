//
// Created by ddf on 18.12.2024.
//

#ifndef ECOSYSTEM_SIMULATION_ACTIONATTACK_H
#define ECOSYSTEM_SIMULATION_ACTIONATTACK_H

#include "Action.h"
#include "Simulation/Animals/Animal.h"

class ActionAttack : public Action{
private:
    int damage;
    std::shared_ptr<Animal> targetAnimal;

public:
    ActionAttack(int damage, std::shared_ptr<Animal> targetAnimal);
    int getDamage() const;
    std::shared_ptr<Animal> getTargetAnimal() const;
};


#endif //ECOSYSTEM_SIMULATION_ACTIONATTACK_H
