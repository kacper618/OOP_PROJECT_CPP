#pragma once
#include "Plant.hpp"

class Belladonna: public Plant
{
    public:
        Belladonna(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        void collision(Organism* attacker) override;
        std::string organism_name() override;
};