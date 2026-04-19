#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "World.hpp"
#include "Organism.hpp"
#include "Wolf.hpp"
#include "Sheep.hpp"
#include "Fox.hpp"
#include "Turtle.hpp"
#include "Antelope.hpp"
#include "Human.hpp"
#include "Grass.hpp"
#include "Sow_thistle.hpp"
#include "Guarana.hpp"
#include "Belladonna.hpp"
#include "Hogweed.hpp"

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

Organism* World::get_organism(int x, int y) const
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

void World::draw_world() const
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

bool World::compare_organisms(Organism* a, Organism* b) 
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

bool World::is_tile_free(int x, int y) const
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

char World::get_human_dir() const
{
    return human_dir;
}

void World::set_human_dir(char dir)
{
    human_dir = dir;
}

void World::save_game(string filename) const
{
    ofstream file(filename);
    if(file.is_open())
    {
        file << turn_number << endl;

        for(size_t i = 0; i < organisms.size(); i++)
        {
            file << organisms[i]->get_save_data() << endl;
        } 
        file.close();
    }
}

void World::load_game(string filename)
{
    ifstream file(filename);

    if(!file.is_open()) return;

    for(size_t i = 0; i < organisms.size(); i++)
    {
        delete organisms[i];
    }

    organisms.clear();

    for(size_t i = 0; i < MAP_Y; i++)
    {
        for(size_t j = 0; j < MAP_X; j++)
        {
            world_map[i][j] = nullptr;
        }
    }

    file >> turn_number;

    char org_char;
    int x, y, s, a;

    while(file >> org_char >> x >> y >> s >> a)
    {
        Organism* organism = nullptr;

        if(org_char == 'W') { organism = new Wolf(x, y, this); }
        else if(org_char == 'S') { organism = new Sheep(x, y, this); }
        else if(org_char == 'F') { organism = new Fox(x, y, this); }
        else if(org_char == 'T') { organism = new Turtle(x, y, this); }
        else if(org_char == 'A') { organism = new Antelope(x, y, this); }
        else if(org_char == 'G') { organism = new Grass(x, y, this); }
        else if(org_char == 'O') { organism = new Sow_thistle(x, y, this); }
        else if(org_char == 'U') { organism = new Guarana(x, y, this); }
        else if(org_char == 'B') { organism = new Belladonna(x, y, this); }
        else if(org_char == 'X') { organism = new Hogweed(x, y, this); }
        else if(org_char == 'H')
        {
            int p_dur, p_cd;
            file >> p_dur >> p_cd;
            Human* H = new Human(x, y, this);
            H->set_potion_cooldown(p_cd);
            H->set_potion_duration(p_dur);
            organism = H;
        }

        if(organism != nullptr)
        {
            organism->set_strength(s);
            organism->set_age(a);
            world_map[y][x] = organism;
            organisms.push_back(organism);
        }
    }
    file.close();
}