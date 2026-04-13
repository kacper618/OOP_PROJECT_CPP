#include <iostream>
#include <algorithm>
#include "World.hpp"
#include "Organism.hpp"

using namespace std;

World::World()
{
    for(int i = 0; i < MAP_Y; i++)
    {
        for(int j = 0; j < MAP_X; j++)
        {
            world_map[i][j] = nullptr;
        }
    }
}

World::~World()
{
    for(size_t i=0; i<organisms.size(); i++)
    {
        delete organisms[i];
    }
}

Organism* World::get_organism(int x, int y)
{
    return world_map[y][x];
}

void World::move_organism(Organism* organism, int x, int y)
{
    int old_x = organism->get_position_x();
    int old_y = organism->get_position_y();

    world_map[old_y][old_x] = nullptr; //cleaning old position

    organism->set_position_x(x);
    organism->set_position_y(y);

    world_map[y][x] = organism;
}

void World::draw_world()
{
    cout << "TURN: " << turn_number << endl;

    for(int i = 0; i < MAP_Y; i++)
    {
        for(int j = 0; j < MAP_X; j++)
        {
            if(world_map[i][j] == nullptr)
            {
                cout << ". ";
            }
            else
            {
                cout << world_map[i][j]->draw() << " ";
            }
        }
        cout << endl;
    }
}

bool compare_organisms(Organism* a, Organism* b)
{
    if(a->get_initiative() != b->get_initiative())
    {
        return a->get_initiative() > b->get_initiative();
    }
    else
    {
        return a->get_age() > b->get_age();
    }
}

void World::make_turn()
{
    turn_number++;  

    sort(organisms.begin(), organisms.end(), compare_organisms);

    for(size_t i = 0; i < organisms.size(); i++)
    {
        if(organisms[i]->get_is_dead())
        {
            continue;
        }

        if(organisms[i]->get_age() > 0)
        {
            organisms[i]->action();
        }
    }

    for(size_t i = 0; i < organisms.size(); i++)
    {
        organisms[i]->increment_age();
    }

    for(int i = organisms.size() - 1; i >= 0; i--)
    {
        if(organisms[i]->get_is_dead())
        {
            if(world_map[organisms[i]->get_position_y()][organisms[i]->get_position_x()] == organisms[i])
            {
                world_map[organisms[i]->get_position_y()][organisms[i]->get_position_x()] = nullptr;
            }
            
            delete organisms[i];
            
            organisms.erase(organisms.begin() + i);
        }
    }
}

bool World::is_tile_free(int x, int y)
{
    if(world_map[y][x] != nullptr)
    {
        return false;
    }

    return true;
}

void World::add_organism(Organism* organism)
{
    world_map[organism->get_position_y()][organism->get_position_x()] = organism;

    organisms.push_back(organism);

    organism->increment_age();
}