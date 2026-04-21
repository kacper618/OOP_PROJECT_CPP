#include <iostream>
#include "Turtle.hpp"
#include "Constants.hpp"

using namespace std;

Turtle::Turtle(int x, int y, World* w)
: Animal(x, y, w, 2, 1)
{
}

char Turtle::draw() const
{
    return 'T';
}

Organism* Turtle::clone(int x, int y)
{
    cout << "Turtle born at: (" << y << ", " << x << ")" << endl;
    return new Turtle(x, y, this->world);
}

void Turtle::action()
{
    int move_chance = rand() % TURTLE_MOVE_CHANCE;

    if(move_chance == 0) //25% chance to move
    {
        Animal::action();
    }
}

bool Turtle::has_deflected_attack(Organism* attacker) const
{
    return attacker->get_strength() < TURTLE_DEFENSE_THRESHOLD;
}

string Turtle::organism_name()
{
    return "Turtle";
}