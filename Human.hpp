#pragma once
#include "Animal.hpp"

class Human: public Animal
{
    public:
        Human(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
        void action() override;
        void magical_potion();
    
    private:
        int potion_duration = 0;
        int potion_cooldown = 0;
};