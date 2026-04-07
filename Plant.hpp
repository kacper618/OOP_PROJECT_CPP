#pragma once
#include "Organism.hpp"

class Plant: public Organism
{
    public:
        void action() override;
        Plant(int x, int y, World* w, int s);
};