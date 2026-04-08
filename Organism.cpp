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

int Organism::get_age()
{
    return age;
}

void Organism::increment_age()
{
    age++;
}