#include <iostream>
#include "Sheep.hpp"

using namespace std;

Sheep::Sheep(int x, int y, World* w)
: Animal(x, y, w, 4, 4)
{
}

char Sheep::draw() const
{
    return 'S';
}

Organism* Sheep::clone(int x, int y)
{
    cout << "Sheep born at: (" << y << ", " << x << ")" << endl;
    return new Sheep(x, y, this->world);
}

string Sheep::organism_name()
{
    return "Sheep";
}