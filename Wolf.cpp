#include <iostream>
#include "Wolf.hpp"

using namespace std;

Wolf::Wolf(int x, int y, World* w)
: Animal(x, y, w, 9, 5)
{
}

char Wolf::draw() const
{
    return 'W';
}

Organism* Wolf::clone(int x, int y)
{
    return new Wolf(x, y ,this->world);
}