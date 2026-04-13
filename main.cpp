#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include "World.hpp"
#include "Organism.hpp"
#include "Constants.hpp"
#include "Grass.hpp"
#include "Wolf.hpp"
#include "Sheep.hpp"
#include "Sow_thistle.hpp"
#include "Guarana.hpp"
#include "Belladonna.hpp"
#include "Sosnowsky's_hogweed.hpp"
#include "Fox.hpp"
#include "Turtle.hpp"
#include "Antelope.hpp"
#include "Human.hpp"

using namespace std;    

int main()
{
    srand(time(nullptr));

    cout << "\033[?25l"; // Hide cursor

    World world;

    Organism* G = new Grass(5, 5, &world);

    Organism* O = new Sow_thistle(9, 9, &world);

    Organism* U1 = new Guarana(4, 7, &world);

    Organism* B = new Belladonna(2, 8, &world);

    Organism* X = new Hogweed(3, 0, &world);

    Organism* W1 = new Wolf(3, 2, &world);
    Organism* W2 = new Wolf(0, 0, &world);

    Organism* F = new Fox(7, 5, &world);

    Organism* T = new Turtle(5, 8, &world);

    Organism* S1 = new Sheep(6, 7, &world);
    Organism* S2 = new Sheep(7, 8, &world);

    Organism* A = new Antelope(4, 9, &world);

    Organism* H = new Human(1, 5, &world);

    world.add_organism(G);
    //world.add_organism(O);
    //world.add_organism(B);
    //world.add_organism(X);
    world.add_organism(U1);
    world.add_organism(W1);
    world.add_organism(W2);
    world.add_organism(F);
    world.add_organism(T);
    world.add_organism(S1);
    world.add_organism(S2);
    world.add_organism(A);
    world.add_organism(H);
    world.draw_world();
    
    while(true)
    {
        int key_input = getch(); 

        if(key_input == 224 || key_input == 0) ////detecting arrows and changing them to WSAD
        {
            key_input = getch(); 
            if(key_input == KEY_UP) key_input = 'w'; 
            if(key_input == KEY_DOWN) key_input = 's';
            if(key_input == KEY_LEFT) key_input = 'a'; 
            if(key_input == KEY_RIGHT) key_input = 'd'; 
        }

        if(key_input == 'q' || key_input == 'Q')
        {
            break;
        }

        if(key_input == 'w' || key_input == 'a' || key_input == 's' || key_input == 'd' || key_input == 'e' || 
           key_input == 'W' || key_input == 'A' || key_input == 'S' || key_input == 'D' || key_input == 'E')
        {
            world.human_dir = key_input; 
            system("cls");
            world.make_turn();
            world.draw_world();
        }
        else if(key_input == ' ')
        {
            world.human_dir = ' '; //human stands still
            system("cls");
            world.make_turn();
            world.draw_world();
        }
    }
    
    return 0;
}