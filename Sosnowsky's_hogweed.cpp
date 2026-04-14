#include <iostream>
#include "Sosnowsky's_hogweed.hpp"
#include "World.hpp"

using namespace std;

Hogweed::Hogweed(int x, int y, World* w)
:  Plant(x, y, w, 10)
{
}

char Hogweed::draw() const
{
    return 'X';
}

Organism* Hogweed::clone(int x, int y)
{
    return new Hogweed(x, y, this->world);
}

void Hogweed::collision(Organism* organism)
{
    organism->set_is_dead(true);

    Plant::collision(organism);
}

void Hogweed::action()
{
   int tile_x[9];
   int tile_y[9];
   int tiles_count = 0;

   get_adjacent_tiles(position_x, position_y, 1, tiles_count, tile_x, tile_y, false);\

   for(int i = 0; i < tiles_count; i++)
   {
        Organism* org = world->get_organism(tile_x[i], tile_y[i]);

        if(org != nullptr && org->is_animal())
        {
            org->set_is_dead(true);
        }
   }

    Plant::action();
}