#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;

const int WIDTH = 25;
const int HEIGHT = 25;


void Game_Draw();
void User_Input();
void Game_Logic();

int main()
{
    char c_userIsAlive;
    while (c_userIsAlive != true){
        Game_Draw();
        Sleep(10);
        system("cls");
    }
    return 0;
}

void Game_Draw()
{
    for (int i = 0; i != HEIGHT; i++){
        if (i == 0 || i == HEIGHT - 1){
            for (int j = 0; j < WIDTH; j++){
                cout << "* ";
            }
            cout << endl;
        }
        else {
            for (int k = 0; k < WIDTH; k++){
                if (k == 0 || k == WIDTH - 1){
                    cout << "* ";
                }
                else{
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}
