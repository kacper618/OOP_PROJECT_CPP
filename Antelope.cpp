#include <iostream>
#include "Antelope.hpp"
#include "World.hpp"

using namespace std;

Antelope::Antelope(int x, int y, World* w)
: Animal(x, y, w, 4, 4)
{
}

char Antelope::draw() const
{
    return 'A';
}

Organism* Antelope::clone(int x, int y)
{
    return new Antelope(x, y, this->world);
}

void Antelope::fight(Organism* organism)
{
    int escape_chance = rand() % 2; //0 or 1

    if(escape_chance == 1) 
    {
        int free_x[25], free_y[25];
        int free_count = 0;

        this->get_adjacent_tiles(position_x, position_y, 1, free_count, free_x, free_y, true);

        if(free_count > 0)
        {
            int rand_tile = rand() % free_count;
            int old_x = position_x;
            int old_y = position_y;

            world->move_organism(this, free_x[rand_tile], free_y[rand_tile]);
            world->move_organism(organism, old_x, old_y);
            
            return; 
        }
    }

    Animal::fight(organism); 
}

int Antelope::get_move_range() const
{
    return 2;
}

