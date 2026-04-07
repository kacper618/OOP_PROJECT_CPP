#include <iostream>
#include <cstdlib>
#include "World.hpp"
#include "Organism.hpp"
#include "Plant.hpp"
#include "Constants.hpp"

using namespace std;

int srand(time(nullptr));

Plant::Plant(int x, int y, World* w, int s)
{
    initiative = 0;
    position_x = x;
    position_y = y;
    world = w;
    strength = s;
}

void Plant::action()
{
    int sow = rand() % 10; //number drawing (0-9)

    if(sow < SOWING_RATE)
    {
        for(int i=position_y-1; i<=position_y+1; i++)
        {
            for(int j=position_x-1; j<=position_x+1; j++)
            {
                bool is_tile_sowed = rand() % 2; //randomly choosing which tile will be sowed

                if(i < 0 && i > MAP_X && j < 0 && j > MAP_Y && is_tile_sowed == 1)
                {
                    
                }
            }
        }
    }
}