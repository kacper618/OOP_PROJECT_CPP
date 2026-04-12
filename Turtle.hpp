#pragma once
#include "Animal.hpp"

class Turtle: public Animal
{
    public:
        Turtle(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
        void action() override;
        void collision(Organism* organism) override;
};