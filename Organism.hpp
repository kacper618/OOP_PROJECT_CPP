#pragma once

class World;

class Organism
{   protected:
        int strength;
        int initiative;
        int position_x, position_y;
        World* world;  

    public:
        virtual void action() = 0;
        virtual void collision() = 0;
        virtual char draw() = 0;
};