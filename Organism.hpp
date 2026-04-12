#pragma once

class World;

class Organism
{   protected:
        int strength;
        int initiative;
        int age;
        int position_x, position_y;
        bool is_dead = false;
        World* world;  

    public:
        virtual void action() = 0;
        virtual void collision(Organism* organism) = 0;
        virtual char draw() = 0;
        virtual Organism* clone(int x, int y) = 0;
        virtual ~Organism();
        virtual bool is_animal();
        int get_initiative();
        int get_strength();
        int get_age();
        int get_position_x();
        int get_position_y();
        bool get_is_dead();
        void set_position_x(int x);
        void set_position_y(int y);
        void set_is_dead(bool d);
        void set_strength(int s);
        void increment_age();
};