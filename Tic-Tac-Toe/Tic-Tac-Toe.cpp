// Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void drawBoard(char board[3][3]) {
    // function draws playing board from board array
    cout << "-----------\n";
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3;j++) {
            cout << board[i][j] << " |";
        }
        cout << "\n";
    }
    cout << "-----------\n";
}
int main()
{
    char board[3][3] = { {' ',' ',' ',},{' ',' ',' ',},{' ',' ',' ',} };// board used for game
    drawBoard(board);
}


