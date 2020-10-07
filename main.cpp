#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

const int WIDTH = 25;
const int HEIGHT = 25;

int snake_HeadX = WIDTH/2;
int snake_HeadY = HEIGHT/2;
int fruit_X = 1;
int fruit_Y = 1;
char user_Input = ' ';

void Game_Draw();
void User_Input();
void Game_Logic();
int Game_Assets(int Draw_X, int Draw_Y, char * Obj_Icon);
void Game_Collision(int &Draw_X, int &Draw_Y);
void Fruit_Randomizer();
void Debugger();

int main()
{
    bool c_userIsAlive = false ;
    while (c_userIsAlive != true){
        Game_Draw();
        User_Input();
        Game_Collision(snake_HeadX, snake_HeadY);
        Debugger();
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
    if (Draw_X == fruit_X && Draw_Y == fruit_Y)
    {
        *OBJ_Icon = '$';
        return 1;
    }

    return 0;
}

void Game_Collision(int &Draw_X, int &Draw_Y)
{
    if (Draw_X > WIDTH - 2)
    {
        Draw_X--;
    }
    if (Draw_X < 1)
    {
        Draw_X++;
    }
    if (Draw_Y > HEIGHT - 2)
    {
        Draw_Y--;
    }
    if (Draw_Y < 1)
    {
        Draw_Y++;
    }

    if ((Draw_X == fruit_X) && (Draw_Y == fruit_Y))
    {
        Game_Logic();
        Fruit_Randomizer();
    }

}

void Fruit_Randomizer()
{
    srand (time(NULL));
    fruit_X = rand() % 24 + 1;
    fruit_Y = rand() % 24 + 1;
}

void Debugger()
{
    cout << "Debugger:" << endl;
    cout << "SnakeX" << snake_HeadX << endl;
    cout << "SnakeY" << snake_HeadY << endl;
    cout << "FruitX" << fruit_X << endl;
    cout << "FruitY" << fruit_Y << endl;
}
