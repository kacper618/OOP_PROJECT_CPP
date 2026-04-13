#include <iostream>
#include "Fox.hpp"
#include "World.hpp"

using namespace std;

Fox::Fox(int x, int y, World* w)
: Animal(x, y, w, 3, 7)
{
}

char Fox::draw()
{
    return 'F';
}

Organism* Fox::clone(int x, int y)
{
    return new Fox(x, y, this->world);
}

void Fox::action()
{
    int tile_x[9]; 
    int tile_y[9];
    int tiles_count = 0;

    for(int i = position_y - 1; i <= position_y + 1; i++)
    {
        for(int j = position_x - 1; j <= position_x + 1; j++)
        {
            if(j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && (j != position_x || i != position_y))
            {
                if(world->is_tile_free(j, i) || world->get_organism(j, i)->get_strength() <= this->strength)
                {
                    tile_x[tiles_count] = j;
                    tile_y[tiles_count] = i;
                    tiles_count++;
                }
            }
        }
    }

    if(tiles_count > 0)
    {
        int rand_new_tile = rand() % tiles_count;

        if(world->is_tile_free(tile_x[rand_new_tile], tile_y[rand_new_tile]))
        {
            world->move_organism(this, tile_x[rand_new_tile], tile_y[rand_new_tile]);
        }
        else
        {
            Organism* defender = world->get_organism(tile_x[rand_new_tile], tile_y[rand_new_tile]);

           defender->collision(this);
        }
    }
}