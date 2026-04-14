#pragma once
#include "Animal.hpp"

class Antelope: public Animal
{
    public:
        Antelope(int x, int y, World* w);
        char draw() const override;
        Organism* clone(int x, int y) override;
        void fight(Organism* organism) override;
        
    protected:
        int get_move_range() const override;
};