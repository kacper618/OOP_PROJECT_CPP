#include <iostream>
#include "Fox.hpp"
#include "World.hpp"

using namespace std;

Fox::Fox(int x, int y, World* w)
: Animal(x, y, w, 3, 7)
{
}

char Fox::draw() const
{
    return 'F';
}

Organism* Fox::clone(int x, int y)
{
    cout << "Fox born at: (" << y << ", " << x << ")" << endl;
    return new Fox(x, y, this->world);
}

void Fox::action()
{
    int tile_x[9];
    int tile_y[9];
    int tile_count = 0;

    get_adjacent_tiles(position_x, position_y, get_move_range(), tile_count, tile_x, tile_y, false);

    int safe_x[9];
    int safe_y[9];
    int safe_count = 0;

    for(int i = 0; i < tile_count; i++)
    {
        Organism* occupant = world->get_organism(tile_x[i], tile_y[i]);
        
        if(occupant == nullptr || occupant->get_strength() <= this->strength)
        {
            safe_x[safe_count] = tile_x[i];
            safe_y[safe_count] = tile_y[i];
            safe_count++;
        }
    }

    if(safe_count > 0)
    {
        move_animal_to_random_tile(safe_count, safe_x, safe_y);
    }
}

string Fox::organism_name()
{
    return "Fox";
}