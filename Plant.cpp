#include <iostream>
#include <cstdlib>
#include "World.hpp"
#include "Organism.hpp"
#include "Plant.hpp"
#include "Constants.hpp"

using namespace std;

Plant::Plant(int x, int y, World* w, int s)
{
    initiative = 0;
    age = 0;
    position_x = x;
    position_y = y;
    world = w;
    strength = s;
}

void Plant::action()
{
    int free_tile_x[9]; 
    int free_tile_y[9];
    int free_tiles_count = 0;

    get_adjacent_tiles(position_x, position_y, 1, free_tiles_count, free_tile_x, free_tile_y, true);

    int sow = rand() % 10;

    if(free_tiles_count > 0)
    {
        if(sow < SOWING_RATE)
        {
            int new_plant_tile = rand() % free_tiles_count;

            Organism* sowed_plant = clone(free_tile_x[new_plant_tile], free_tile_y[new_plant_tile]);
            world->add_organism(sowed_plant); 
        }
    }
        
}

void Plant::collision(Organism* organism)
{
    this->set_is_dead(true);
    world->move_organism(organism, this->position_x, this->position_y);
}