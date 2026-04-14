#pragma once
#include "Animal.hpp"

class Sheep: public Animal
{
    public:
        Sheep(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        std::string organism_name() override;
};