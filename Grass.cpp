#include <iostream>
#include "Grass.hpp"

using namespace std;

Grass::Grass(int x, int y, World* w)
: Plant(x, y, w, 0)
{
}

char Grass::draw() const
{
    return 'G';
}

Organism* Grass::clone(int x, int y)
{
    cout << "Grass sowed at: (" << y << ", " << x << ")" << endl;
    return new Grass(x, y, this->world);
}

string Grass::organism_name()
{
    return "Grass";
}