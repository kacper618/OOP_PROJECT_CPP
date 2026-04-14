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
        virtual void get_adjacent_tiles(int organism_x, int organism_y, int range, int& t_count, int t_x[], int t_y[], bool only_free = false);

    public:
        virtual void action() = 0;
        virtual void collision(Organism* organism) = 0;
        virtual char draw() const = 0;
        virtual Organism* clone(int x, int y) = 0;
        virtual ~Organism();
        virtual bool is_animal() const;
        virtual bool has_deflected_attack(Organism* organism) const;
        int get_initiative() const;
        int get_strength() const;
        int get_age() const;
        int get_position_x() const;
        int get_position_y() const;
        bool get_is_dead() const;
        void set_position_x(int x);
        void set_position_y(int y);
        void set_is_dead(bool d);
        void set_strength(int s);
        void increment_age();
};