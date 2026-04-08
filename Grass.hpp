#pragma once
#include "Plant.hpp"

class Grass: public Plant
{
    public:
        Grass(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
};