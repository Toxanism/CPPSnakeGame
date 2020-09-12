#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int WIDTH = 25;
const int HEIGHT = 25;

int snake_HeadX = WIDTH/2;
int snake_HeadY = HEIGHT/2;
char user_Input = ' ';

void Game_Draw();
void User_Input();
void Game_Logic();
int Game_Assets(int Draw_X, int Draw_Y, char * Obj_Icon);
void Game_Collision(int Draw_X, int Draw_Y);

int main()
{
    bool c_userIsAlive = false ;
    while (c_userIsAlive != true){
        Game_Draw();
        User_Input();
        Sleep(100);
        system("cls");
    }
    return 0;
}

void Game_Draw()
{
    char Obj_Icon = ' ';
    for (int i = 0; i != HEIGHT; i++)
        {
        if (i == 0 || i == HEIGHT - 1)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        else
        {
            for (int k = 0; k < WIDTH; k++)
            {
                if (k == 0 || k == WIDTH - 1)
                {
                    cout << "* ";
                }
                else if(Game_Assets(k, i, &Obj_Icon))
                {
                    cout << Obj_Icon << ' ';
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}

void User_Input()
{
    if (kbhit())
    {
        user_Input = _getch();
        switch(user_Input)
        {
        case 'a':
            snake_HeadX--;
            break;
        case 'd':
        snake_HeadX++;
            break;
        case 's':
            snake_HeadY++;
            break;
        case 'w':
            snake_HeadY--;
            break;
        default:
            return;
        }
    }
    else
        switch(user_Input)
        {
        case 'a':
            snake_HeadX--;
            break;
        case 'd':
            snake_HeadX++;
            break;
        case 's':
            snake_HeadY++;
            break;
        case 'w':
            snake_HeadY--;
            break;
        default:
            return;
        }
}

void Game_Logic()
{

}

int Game_Assets(int Draw_X, int Draw_Y, char * OBJ_Icon)
{
    if (Draw_X == snake_HeadX && Draw_Y == snake_HeadY)
    {
        *OBJ_Icon = '@';
        return 1;
    }

    return 0;
}

void Game_Collision(int Draw_X, int Draw_Y)
{

}
