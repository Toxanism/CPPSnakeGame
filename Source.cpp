#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <Windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

const int WIDTH = 25;
const int HEIGHT = 25;

bool c_userIsAlive;
int snake_HeadX = WIDTH / 2;
int snake_HeadY = HEIGHT / 2;
int tailX[100], tailY[100];
int nTail = 0;
int fruit_X;
int fruit_Y;
char user_Input = ' ';
int score = 0;

void Game_Draw();
void User_Input();
int Game_Assets(int Draw_X, int Draw_Y, char* Obj_Icon);
void Fruit_Randomizer();
void Debugger();
void Game_Logic();

int main()
{
    c_userIsAlive = true;
    Fruit_Randomizer();
    while (c_userIsAlive != false) {
        Game_Draw();
        User_Input();
        Game_Logic();
        Debugger();
        Sleep(10);
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
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for (int k = 0; k < WIDTH; k++)
            {
                if (k == 0 || k == WIDTH - 1)
                {
                    cout << "*";
                }
                else if (Game_Assets(k, i, &Obj_Icon))
                {
                    cout << Obj_Icon;
                }
                else
                {
                    bool print = false;
                    for (int u = 0; u < nTail; u++)
                    {
                        if (tailX[u] == k && tailY[u] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }
            }
            cout << endl;
        }
    }
}

void User_Input()
{
    
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snake_HeadX;
    tailY[0] = snake_HeadY;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if (_kbhit())
    {
        user_Input = _getch();
        switch (user_Input)
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
        case 'p':
            Debugger();
            _getch();
            break;
        default:
            return;
        }
    }
    else
        switch (user_Input)
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
    
    if (snake_HeadX > WIDTH - 2 || snake_HeadX < 1 || snake_HeadY > HEIGHT - 2 || snake_HeadY < 1)
    {
        c_userIsAlive = false;
    }
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == snake_HeadX && tailY[i] == snake_HeadY)
            c_userIsAlive = false;
    if ((snake_HeadX == fruit_X) && (snake_HeadY == fruit_Y))
    {
        score++;
        nTail++;
        Fruit_Randomizer();
    }
}

int Game_Assets(int Draw_X, int Draw_Y, char* OBJ_Icon)
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

void Fruit_Randomizer()
{
    srand(time(NULL));
    fruit_X = rand() % 23 + 1;
    fruit_Y = rand() % 23 + 1;
}

void Debugger()
{
    cout << "Debugger:" << endl;
    cout << "SnakeX" << snake_HeadX << endl;
    cout << "SnakeY" << snake_HeadY << endl;
    cout << "FruitX" << fruit_X << endl;
    cout << "FruitY" << fruit_Y << endl;
    cout << "TailX" << tailX[0] << endl;
    cout << "TailY" << tailY[0] << endl;

}
