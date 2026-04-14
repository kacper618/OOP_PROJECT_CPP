#pragma once
#include "Animal.hpp"

class Human: public Animal
{
    public:
        Human(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        void action() override;
        void magical_potion();
        std::string organism_name() override;
    private:
        int potion_duration = 0;
        int potion_cooldown = 0;
};