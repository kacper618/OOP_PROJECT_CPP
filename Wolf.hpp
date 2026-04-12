#pragma once
#include "Animal.hpp"

class Wolf: public Animal
{
    public:
        Wolf(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
};