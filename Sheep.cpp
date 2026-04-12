#include <iostream>
#include "Sheep.hpp"

using namespace std;

Sheep::Sheep(int x, int y, World* w)
: Animal(x, y, w, 4, 4)
{
}

char Sheep::draw()
{
    return 'S';
}

Organism* Sheep::clone(int x, int y)
{
    return new Sheep(x, y, this->world);
}