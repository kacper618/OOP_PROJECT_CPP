#pragma once
#include <vector>
#include "Constants.hpp"

class Organism;

class World
{
    Organism* world_map[MAP_Y][MAP_X];
    int turn_number = 0;
    std::vector<Organism*> organisms;
    char human_dir;

    public:
        World();
        virtual ~World();
        Organism* get_organism(int x, int y) const;
        void move_organism(Organism* organism, int x, int y);
        void draw_world() const;
        void make_turn();
        bool is_tile_free(int x, int y) const;
        void add_organism(Organism* organism);
        static bool compare_organisms(Organism* a, Organism* b);
        void set_human_dir(char dir);
        char get_human_dir() const;
};