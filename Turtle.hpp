#pragma once
#include "Animal.hpp"

class Turtle: public Animal
{
    public:
        Turtle(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        void action() override;
        bool has_deflected_attack(Organism* attacker) const override;
        std::string organism_name() override;
};