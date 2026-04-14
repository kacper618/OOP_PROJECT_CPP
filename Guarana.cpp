#include <iostream>
#include "Guarana.hpp"

using namespace std;

Guarana::Guarana(int x, int y, World* w)
: Plant(x, y, w, 0)
{
}

char Guarana::draw() const
{
    return 'U';
}

Organism* Guarana::clone(int x, int y)
{
    cout << "Guarana sowed at: (" << y << ", " << x << ")" << endl;
    return new Guarana(x, y, this->world);
}

void Guarana::collision(Organism* organism)
{
    organism->set_strength(organism->get_strength() + 3);

    Plant::collision(organism);
}

string Guarana::organism_name()
{
    return "Guarana";
}