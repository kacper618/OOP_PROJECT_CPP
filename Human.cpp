#include <iostream>
#include <conio.h>
#include "Human.hpp"
#include "Constants.hpp"
#include "World.hpp"

using namespace std;

Human::Human(int x, int y, World* w)
: Animal(x, y, w, 5, 4)
{
}

char Human::draw()
{
    return 'H';
}

Organism* Human::clone(int x, int y)
{
    return new Human(x, y, this->world);
}

void Human::action()
{
    int target_x = position_x;
    int target_y = position_y;
    
    char current_key = world->human_dir; 

    if(current_key == 'e' || current_key == 'E') { magical_potion(); return; }
    else if(current_key == 'w' || current_key == 'W') { target_y--; }
    else if(current_key == 's' || current_key == 'S') { target_y++; }
    else if(current_key == 'a' || current_key == 'A') { target_x--; }
    else if(current_key == 'd' || current_key == 'D') { target_x++; }

    if(target_x >= 0 && target_x < MAP_X && target_y >= 0 && target_y < MAP_Y)
    {
        if(world->get_organism(target_x, target_y) == nullptr)
        {
            world->move_organism(this, target_x, target_y);
        }
        else
        {
            Organism* defender = world->get_organism(target_x, target_y);
            defender->collision(this);
        }
    }

    if(potion_duration > 0)
    {
        potion_duration--;
        strength--;
    }
    if(potion_cooldown > 0)
    {
        potion_cooldown--;
    }
}

void Human::magical_potion()
{
    if(potion_cooldown == 0)
    {
        potion_duration = 5;
        potion_cooldown = 10;

        strength += potion_duration;
    }
}

