#include <string>
#include "Organism.hpp"
#include "Constants.hpp"
#include "World.hpp"

using namespace std;

Organism::~Organism()
{
}

int Organism::get_position_x() const
{
    return position_x;
}

int Organism::get_position_y() const
{
    return position_y;
}

int Organism::get_initiative() const
{
    return initiative;
}

int Organism::get_strength() const
{
    return strength;
}

bool Organism::get_is_dead() const
{
    return is_dead;
}

bool Organism::is_animal() const
{
    return false;
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

void Organism::set_strength(int s)
{
    strength = s;
}

void Organism::set_age(int a)
{
    age = a;
}

int Organism::get_age() const
{
    return age;
}

void Organism::increment_age()
{
    age++;
}

void Organism::get_adjacent_tiles(int organism_x, int organism_y, int range, int& t_count, int t_x[], int t_y[], bool only_free)
{
    t_count = 0;

    for(int i = organism_y - range; i <= organism_y + range; i++) //checking all tiles in 3x3 square around the current organism position
    {
        for(int j = organism_x - range; j <= organism_x + range; j++)
        {
            if(j >= 0 && j < MAP_X && i >= 0 && i < MAP_Y && (j != organism_x || i != organism_y)) //checking if tile is on map and if it is not current organism position
            {
                if(only_free && world->get_organism(j, i) != nullptr) //if free tiles are required, occupied ones are ommited
                {
                    continue;
                }

                t_x[t_count] = j;
                t_y[t_count] = i;
                t_count++;
            }
        }
    }
}

bool Organism::has_deflected_attack(Organism* organism) const
{
    return false;
}

string Organism::get_save_data() const
{
    return string(1, this->draw()) + " " +
    to_string(position_x) + " " +
    to_string(position_y) + " " +
    to_string(strength) + " " +
    to_string(age);
}
