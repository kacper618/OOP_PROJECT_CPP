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

void Animal::move_animal_to_random_tile(int& t_count, int t_x[], int t_y[])
{
    int rand_new_tile = rand() % t_count;

        if(world->is_tile_free(t_x[rand_new_tile], t_y[rand_new_tile]))
        {
            world->move_organism(this, t_x[rand_new_tile], t_y[rand_new_tile]);
        }
        else
        {
            Organism* defender = world->get_organism(t_x[rand_new_tile], t_y[rand_new_tile]);

           defender->collision(this);
        }
}

void Animal::action()
{
    int tile_x[25]; 
    int tile_y[25];
    int tiles_count = 0;

    get_adjacent_tiles(position_x, position_y, get_move_range(), tiles_count, tile_x, tile_y, false);

    if(tiles_count > 0)
    {
        move_animal_to_random_tile(tiles_count, tile_x, tile_y);
    }
}

void Animal::collision(Organism* organism)
{
    if(this->has_deflected_attack(organism))
    {
        return;
    }

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

    get_adjacent_tiles(organism->get_position_x(), organism->get_position_y(), 1, free_tiles_count, free_tile_x, free_tile_y, true);

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
        
        cout << this->organism_name() << " was attacked and killed by " << organism->organism_name() 
        << ": (" << organism->get_position_y() << ", " << organism->get_position_y() << ")" << endl;
    }
    else
    {
        organism->set_is_dead(true);

        cout << this->organism_name() << " defended itself from " << organism->organism_name() 
        << ": (" << this->get_position_y() << ", " << this->get_position_y() << ")" << endl;
    }
}

bool Animal::is_animal() const
{
    return true;
}

int Animal::get_move_range() const
{
    return 1;
}
