#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include "World.hpp"
#include "Organism.hpp"
#include "Plant.hpp"
#include "Grass.hpp"

using namespace std;

int main()
{
    srand(time(nullptr));

    cout << "\033[?25l"; // Hide cursor

    World world;

    Organism* G = new Grass(5, 5, &world);

    world.add_organism(G);
    world.draw_world();
    
    while(true)
    {
        char key_input = getch();

        if(key_input == 'q')
        {
            break;
        }
        else if(key_input == ' ')
        {
            system("cls");
            world.make_turn();
            world.draw_world();
        }
    }
    
    return 0;
}