#pragma once
#include "Plant.hpp"

class Sow_thistle: public Plant
{
    public:
        Sow_thistle(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
        void action() override;
};