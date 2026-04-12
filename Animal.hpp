#pragma once
#include "Organism.hpp"

class Animal: public Organism
{
    public:
        Animal(int x, int y, World* w, int s, int i);
        void action() override;
        void collision(Organism* organism) override;
        bool is_animal() override;
    protected:
        void reproduce(Organism* organism);
        void fight(Organism* organism);
};