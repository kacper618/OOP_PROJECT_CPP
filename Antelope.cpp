#include <iostream>
#include "Antelope.hpp"
#include "World.hpp"

using namespace std;

Antelope::Antelope(int x, int y, World* w)
: Animal(x, y, w, 4, 4)
{
}

char Antelope::draw()
{
    return 'A';
}

Organism* Antelope::clone(int x, int y)
{
    return new Antelope(x, y, this->world);
}

void Antelope::action()
{
    int tile_x[25]; 
    int tile_y[25];
    int tiles_count = 0;

    for(int i = position_y - 2; i <= position_y + 2; i++)
    {
        for(int j = position_x - 2; j <= position_x + 2; j++)
        {
            if(j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && (j != position_x || i != position_y))
            {
                tile_x[tiles_count] = j;
                tile_y[tiles_count] = i;
                tiles_count++;
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

void Antelope::collision(Organism* organism)
{
    if(this->draw() == organism->draw())
    {
        Animal::collision(organism);
    }
    else
    {
        int escape_chance = rand() % 2;

        int tile_x[9];
        int tile_y[9];
        int free_tiles_count = 0;

        if(escape_chance == 1) //escape
        {
            for(int i = position_y - 1; i <= position_y + 1; i++)
            {
                for(int j = position_x - 1; j <= position_x + 1; j++)
                {
                    if(j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && (j != position_x || i != position_y) && world->is_tile_free(j, i))
                    {
                        tile_x[free_tiles_count] = j;
                        tile_y[free_tiles_count] = i;
                        free_tiles_count++;
                    }
                }
            }

            if(free_tiles_count > 0)
            {
                int rand_free_tile = rand() % free_tiles_count;

                int antelope_x = position_x;
                int antelope_y = position_y;

                world->move_organism(this, tile_x[rand_free_tile], tile_y[rand_free_tile]);

                world->move_organism(organism, antelope_x, antelope_y);
            }
            else
            {
                Animal::collision(organism);
            }
        }
        else // no escape
        {
            Animal::collision(organism);
        }   
    }
}