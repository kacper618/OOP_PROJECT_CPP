#pragma once
#include "Plant.hpp"

class Hogweed: public Plant
{
    public:
        Hogweed(int x, int y, World* w);
        char draw() override;
        Organism* clone(int x, int y) override;
        void collision(Organism* Organism) override;
        void action() override;
};