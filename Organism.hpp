#pragma once

class World;

class Organism
{   protected:
        int strength;
        int initiative;
        int age;
        int position_x, position_y;
        World* world;  

    public:
        virtual void action() = 0;
        virtual void collision() = 0;
        virtual char draw() = 0;
        virtual Organism* clone(int x, int y) = 0;
        virtual ~Organism();
        int get_initiative();
        int get_age();
        int get_position_x();
        int get_position_y();
        void increment_age();
};