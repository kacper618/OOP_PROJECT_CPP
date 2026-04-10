#pragma once
#include "Organism.hpp"

class Plant: public Organism
{
    public:
        Plant(int x, int y, World* w, int s);
        void action() override;
        void collision(Organism* organism) override;
};