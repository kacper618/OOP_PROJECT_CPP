#include <iostream>
#include "World.hpp"
#include "Organism.hpp"
#include "Animal.hpp"

using namespace std;

Animal::Animal(int x, int y, World* w, int s, int i)
{
    age = 0;
    position_x = x;
    position_y = y;
    world = w;
    strength = s;
    initiative = i;
}

void Animal::action()
{
    int tile_x[9]; //there are 9 tiles (1 central tile + 8 tiles around)
    int tile_y[9];
    int tiles_count = 0;

    for(int i = position_y - 1; i <= position_y + 1; i++)
    {
        for(int j = position_x - 1; j <= position_x + 1; j++)
        {
            if(j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && (j != position_x || i != position_y))
            //checking if tile is not the central tile and if it is in map bounds
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

void Animal::collision(Organism* organism)
{
    if(this->draw() == organism->draw())
    {
        reproduce(organism);
    }
    else
    {
        fight(organism);
    }
}

void Animal::reproduce(Organism* organism)
{
    int free_tile_x[9];
    int free_tile_y[9];
    int free_tiles_count = 0;

    for(int i = organism->get_position_y() - 1; i <= organism->get_position_y() + 1; i++)
    {
        for(int j = organism->get_position_x() - 1; j <= organism->get_position_x() + 1; j++)
        {
            if (j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && world->is_tile_free(j, i))
            //checking if the tile is free (not occupied by any organism) and if it is in map bounds
            {
                free_tile_x[free_tiles_count] = j;
                free_tile_y[free_tiles_count] = i;
                free_tiles_count++;
            }
        }
    }

    if(free_tiles_count > 0)
    {
        int rand_free_tile = rand() % free_tiles_count;

        Organism* baby = clone(free_tile_x[rand_free_tile], free_tile_y[rand_free_tile]);
        world->add_organism(baby);
    }
}

void Animal::fight(Organism* organism)
{
    if(organism->get_strength() >= this->strength)
    {
        world->move_organism(organism, this->get_position_x(), this->get_position_y());
        
        this->set_is_dead(true);
    }
    else
    {
        organism->set_is_dead(true);
    }
}

bool Animal::is_animal()
{
    return true;
}