#include <iostream>
#include "Turtle.hpp"

using namespace std;

Turtle::Turtle(int x, int y, World* w)
: Animal(x, y, w, 2, 1)
{
}

char Turtle::draw()
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

void Turtle::collision(Organism* organism)
{   
    if(this->draw() == organism->draw()) //breeding
    {
        Animal::collision(organism);
    }
    else if(organism->get_strength() < 5) //reflecting attack
    {
    }
    else
    {
        Animal::collision(organism); //fighting
    }
}