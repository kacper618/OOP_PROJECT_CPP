#include <iostream>
#include "Sow_thistle.hpp"

using namespace std;

Sow_thistle::Sow_thistle(int x, int y, World* w)
: Plant(x, y, w, 0)
{
}

char Sow_thistle::draw()
{
    return 'O';
}

Organism* Sow_thistle::clone(int x, int y)
{
    return new Sow_thistle(x, y, this->world);
}

void Sow_thistle::action()
{
    for(int i = 0; i < 3; i++)
    {
        Plant::action();
    }
}