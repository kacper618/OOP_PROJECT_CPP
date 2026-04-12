#pragma once
#include "Animal.hpp"

class Fox: public Animal
{
    public:
        Fox(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
        void action() override;
};