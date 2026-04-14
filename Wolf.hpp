#pragma once
#include "Animal.hpp"

class Wolf: public Animal
{
    public:
        Wolf(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        std::string organism_name() override;
};