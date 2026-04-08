#include "Grass.hpp"

using namespace std;

Grass::Grass(int x, int y, World* w)
: Plant(x, y, w, 0)
{
}

char Grass::draw()
{
    return 'G';
}

Organism* Grass::clone(int x, int y)
{
    return new Grass(x, y, this->world);
}