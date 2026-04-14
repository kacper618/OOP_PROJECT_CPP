#include <iostream>
#include "Belladonna.hpp"

using namespace std;

Belladonna::Belladonna(int x, int y, World* w)
: Plant(x, y, w, 99)
{
}

char Belladonna::draw() const
{
    return 'B';
}

Organism* Belladonna::clone(int x, int y)
{
    cout << "Belladonna sowed at: (" << y << ", " << x << ")" << endl;
    return new Belladonna(x, y, this->world);
}

void Belladonna::collision(Organism* organism)
{
    organism->set_is_dead(true);

    Plant::collision(organism);
}

string Belladonna::organism_name()
{
    return "Belladonna";
}

