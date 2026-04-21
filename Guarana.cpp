#include <iostream>
#include "Guarana.hpp"
#include "Constants.hpp"

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

void Guarana::collision(Organism* attacker)
{
    attacker->set_strength(attacker->get_strength() + GUARANA_STRENGTH_BONUS);

    Plant::collision(attacker);
}

string Guarana::organism_name()
{
    return "Guarana";
}