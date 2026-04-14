#pragma once
#include "Plant.hpp"

class Guarana: public Plant
{
    public:
        Guarana(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        void collision(Organism* organism) override;
        std::string organism_name() override;
};