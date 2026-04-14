#include <iostream>
#include "Turtle.hpp"

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
    return new Turtle(x, y, this->world);
}

void Turtle::action()
{
    int move_chance = rand() % 4;

    if(move_chance == 0) //25% chance to move
    {
        Animal::action();
    }
}

bool Turtle::has_deflected_attack(Organism* organism) const
{
    return true;
}