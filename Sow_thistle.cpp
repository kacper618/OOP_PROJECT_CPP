#include <iostream>
#include "Sow_thistle.hpp"
#include "Constants.hpp"

using namespace std;

Sow_thistle::Sow_thistle(int x, int y, World* w)
: Plant(x, y, w, 0)
{
}

char Sow_thistle::draw() const
{
    return 'O';
}

Organism* Sow_thistle::clone(int x, int y)
{
    cout << "Sow thistle sowed at: (" << y << ", " << x << ")" << endl;
    return new Sow_thistle(x, y, this->world);
}

void Sow_thistle::action()
{
    for(int i = 0; i < SOW_THISTLE_ATTEMPTS; i++)
    {
        Plant::action();
    }
}

string Sow_thistle::organism_name()
{
    return "Sow thistle";
}