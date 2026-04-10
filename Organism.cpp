#include "Organism.hpp"

Organism::~Organism()
{
}

int Organism::get_position_x()
{
    return position_x;
}

int Organism::get_position_y()
{
    return position_y;
}

int Organism::get_initiative()
{
    return initiative;
}

bool Organism::get_is_dead()
{
    return is_dead;
}

void Organism::set_position_x(int x)
{
    position_x = x;
}

void Organism::set_position_y(int y)
{
    position_y = y;
}

void Organism::set_is_dead(bool d)
{
    is_dead = d;
}

int Organism::get_age()
{
    return age;
}


void Organism::increment_age()
{
    age++;
}