#pragma once
#include "Constants.hpp"

class Organism;

class World
{
    Organism* world_map[MAP_X][MAP_Y];
    int turn_number = 0;

    public:
        World();
        virtual ~World();
        void draw_world();
        void make_turn();
};