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
    int free_tile_x[9]; //there are 9 tiles (1 central tile + 8 tiles around)
    int free_tile_y[9];
    int free_tiles_count = 0;

    for(int i=position_y-1; i<=position_y+1; i++)
    {
        for(int j=position_x-1; j<=position_x+1; j++)
        {
            if (j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && (j != position_x || i != position_y) && world->is_tile_free(j, i))
            //Checking if current tile:
            //1) is not out of map bounds
            //2) is not the current plant position
            //3) is empty
            {
                free_tile_x[free_tiles_count] = j;
                free_tile_y[free_tiles_count] = i;
                free_tiles_count++;
            }
        }
    }

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

void Plant::collision()
{
}