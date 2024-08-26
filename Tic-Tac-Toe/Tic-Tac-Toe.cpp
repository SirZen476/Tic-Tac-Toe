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
void SinglePlayer() {
    char board[3][3] = { {' ',' ',' ',},{' ',' ',' ',},{' ',' ',' ',} };// board used for game
    char player1 = 'X';
    int turn;
    int row, col;
    bool win = false;
    cout << "Single-Player Mode\n";
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
        cout << "You won in " << turn << "turns\n";
    }
    else {
        cout << "You Lost\n";
    }
}

void MultiPlayer() {
    char board[3][3] = { {' ',' ',' ',},{' ',' ',' ',},{' ',' ',' ',} };// board used for game
    char player[2] = {'X','O'};
    int turn;
    int active = 0;// to track active player - 0 for player 1 ,1 for player 2
    int row, col;
    bool win = false;
    cout << "Multiplayer-Player Mode\n";
    cout << "Player 1: " << player[0] << "\n";
    cout << "Player 2: " << player[1] << "\n";
    for (turn = 1; turn < 10; turn++) {// game loop
        drawBoard(board);
        while (true) {
            cout << "Player " << active+1 << " , Please enter row ,press ENTER and then enter column and press ENTER (range 0 to 2)\n";
            cin >> row >> col;
            if (col < 0 || col>2 || row < 0 || row>2 || board[row][col] != ' ') {
                cout << "Invalid move, Try Again\n";
            }
            else break;
        }
        board[row][col] = player[active];
        win = checkWin(board, player[active]);
        if (win) {
            break;
        }
        //change turns mechanics
        if (active == 0) active = 1;
        else active = 0; 
    }
    drawBoard(board);
    if (win) {
        cout << "Player " <<active+1 <<" won in " << turn << "turns\n";
    }
    else {
        cout << "It's a tie!\n";
    }
}

int main(){
    int players;
    while (true) {
        cout << "Welcome to Tic-Tac-Toe! enter 1 for SinglePlayer or 2 for two players\n";
        cin >> players;
        if (players == 1) {
            SinglePlayer();
            break;
        }
        if (players == 2) {
            MultiPlayer();
            break;
        }
        else {
            cout << "invalid Input. try again \n";
        }
    }
}


