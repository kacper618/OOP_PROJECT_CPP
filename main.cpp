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
#include "Hogweed.hpp"
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

    Organism* O = new Sow_thistle(8, 9, &world);

    Organism* U = new Guarana(4, 7, &world);

    Organism* B = new Belladonna(18, 8, &world);

    Organism* X = new Hogweed(13, 19, &world);

    Organism* W1 = new Wolf(3, 2, &world);
    Organism* W2 = new Wolf(0, 11, &world);

    Organism* F1 = new Fox(7, 5, &world);
    Organism* F2 = new Fox(10, 9, &world);

    Organism* T1 = new Turtle(5, 8, &world);
    Organism* T2 = new Turtle(19, 19, &world);

    Organism* S1 = new Sheep(0, 7, &world);
    Organism* S2 = new Sheep(13, 8, &world);

    Organism* A1 = new Antelope(4, 9, &world);
    Organism* A2 = new Antelope(13, 0, &world);

    Organism* H = new Human(1, 5, &world);

    world.add_organism(G);
    world.add_organism(O);
    world.add_organism(B);
    world.add_organism(X);
    world.add_organism(U);
    world.add_organism(W1);
    world.add_organism(W2);
    world.add_organism(F1);
    world.add_organism(F2);
    world.add_organism(T1);
    world.add_organism(T2);
    world.add_organism(S1);
    world.add_organism(S2);
    world.add_organism(A1);
    world.add_organism(A2);
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
        else if(key_input == 'z' || key_input == 'Z')
        {
            world.save_game("save.txt");
            cout << "----GAME SAVED---" << endl;
        }
        else if(key_input == 'x' || key_input == 'X')
        {
            world.load_game("save.txt");
            system("cls");
            world.draw_world();
            cout << "---GAME LOADED----" << endl;
        }

        if(key_input == 'w' || key_input == 'a' || key_input == 's' || key_input == 'd' || key_input == 'e' || 
           key_input == 'W' || key_input == 'A' || key_input == 'S' || key_input == 'D' || key_input == 'E')
        {
            world.set_human_dir(key_input); 
            system("cls");
            world.make_turn();
            world.draw_world();
        }
        else if(key_input == ' ')
        {
            world.set_human_dir(' '); //human stands still
            system("cls");
            world.make_turn();
            world.draw_world();
        }
    }

    return 0;
}