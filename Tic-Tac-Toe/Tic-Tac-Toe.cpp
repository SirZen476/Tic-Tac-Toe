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
bool checkWin(char board[3][3], char player){
    // function to check if a player won
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if( (board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}
int main(){
    char board[3][3] = { {' ',' ',' ',},{' ',' ',' ',},{' ',' ',' ',} };// board used for game
    char player1 = 'X';
    int turn;
    int row, col;
    bool win = false;
    cout << "Welcome to Tic-Tac-Toe!/n";
    for (turn = 1; turn < 10; turn++) {// game loop
        drawBoard(board);
        while (true) {
            cout << "Player " << player1 << " , Please enter row ,press ENTER and then enter column and press ENTER (range 0 to 2)\n";
            cin >> row >> col;
            if (col < 0 || col>2 || row < 0 || row>2 || board[row][col] != ' ') {
                cout << "Invalid move, Try Again\n";
            }
            else break;
        }
        board[row][col] = player1;
        win = checkWin(board, player1);
        if (win) {
            break;
        }
    }
    drawBoard(board);
    if (win) {
        cout<< "You won in "<< turn << "turns\n";
    }
    else {
        cout << "You Lost\n";
    }

}


