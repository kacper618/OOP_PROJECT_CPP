#pragma once
#include "Plant.hpp"

class Grass: public Plant
{
    public:
        Grass(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        std::string organism_name() override;
};