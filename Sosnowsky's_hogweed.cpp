#include <iostream>
#include "Sosnowsky's_hogweed.hpp"
#include "World.hpp"

using namespace std;

Hogweed::Hogweed(int x, int y, World* w)
:  Plant(x, y, w, 10)
{
}

char Hogweed::draw()
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
    for(int i = position_y - 1; i <= position_y + 1; i++)
    {
        for(int j = position_x - 1; j <= position_x + 1; j++)
        {
            if (j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && (i != position_y || j != position_x))
            {
                Organism* org = world->get_organism(j, i);
                if(org != nullptr && org->is_animal())
                {
                    org->set_is_dead(true);
                }
            }
        }
    }

    Plant::action();
}