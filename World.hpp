#pragma once
#include <vector>
#include "Constants.hpp"

class Organism;

class World
{
    Organism* world_map[MAP_Y][MAP_X];
    int turn_number = 0;
    std::vector<Organism*> organisms;

    public:
        World();
        virtual ~World();
        Organism* get_organism(int x, int y);
        void move_organism(Organism* organism, int x, int y);
        void draw_world();
        void make_turn();
        bool is_tile_free(int x, int y);
        void add_organism(Organism* organism);
        char human_dir;
};