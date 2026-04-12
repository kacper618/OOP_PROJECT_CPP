#pragma once
#include "Animal.hpp"

class Sheep: public Animal
{
    public:
        Sheep(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
};