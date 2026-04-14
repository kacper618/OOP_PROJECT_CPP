#pragma once
#include "Organism.hpp"

class Animal: public Organism
{
    public:
        Animal(int x, int y, World* w, int s, int i);
        void action() override;
        void collision(Organism* organism) override;
        bool is_animal() const override;
    protected:
        void move_animal_to_random_tile(int& t_count, int t_x[], int t_y[]);
        void reproduce(Organism* organism);
        virtual void fight(Organism* organism);
        virtual int get_move_range() const;
};