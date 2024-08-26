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
bool checkWin(){
    //function that checks if player wins. currently for 1 player only
    return false;
}
int main(){
    char board[3][3] = { {' ',' ',' ',},{' ',' ',' ',},{' ',' ',' ',} };// board used for game
    char player1 = 'X';
    int turn;
    int row, col;
    cout << "Welcome to Tic-Tac-Toe!/n";
    for (turn = 1; turn < 10; turn++) {
        drawBoard(board);
        while (true) {
            cout << "Player " << player1 << " , Please enter row ,press ENTER and then enter column and press ENTER (range 0 to 2)";
            cin >> row >> col;
            if (col < 0 || col>2 || row < 0 || row>2 || board[row][col] != ' ') {
                cout << "Invalid move, Try Again\n";
            }
            else break;
        }
        board[row][col] = player1;

    }

}


