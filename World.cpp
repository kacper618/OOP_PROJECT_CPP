#include <iostream>
#include "World.hpp"
#include "Organism.hpp"

using namespace std;

World::World()
{
    cout << "TURN: " << turn_number << endl;
    for(int i=0; i<MAP_X; i++)
    {
        for(int j=0; j<MAP_Y; j++)
        {
            world_map[i][j] = nullptr;
        }
    }

    for(int i=0; i<MAP_X; i++)
    {
        for(int j=0; j<MAP_Y; j++)
        {
            if(world_map[i][j] == nullptr)
            {
                cout << ". ";
            }
            else
            {
                world_map[i][j]->draw();
            }
        }
        cout << endl;
    }
}

World::~World()
{
};

void World::draw_world()
{
    cout << "TURN: " << turn_number << endl;

    for(int i=0; i<MAP_X; i++)
    {
        for(int j=0; j<MAP_Y; j++)
        {
            if(world_map[i][j] == nullptr)
            {
                cout << ". ";
            }
            else
            {
                world_map[i][j]->draw();
            }
        }
        cout << endl;
    }
}

void World::make_turn()
{
    turn_number++;  
};