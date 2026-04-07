#include <iostream>
#include <conio.h>
#include "World.hpp"

using namespace std;

int main()
{
    World world;

    cout << "\033[?25l"; // Hide cursor

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