#include <iostream>
#include <climits>
#include <ctime>
using namespace std;

struct GameBoard {
    char** board;
    int size;
};
int boardSize;

GameBoard createGameBoard(int n);


int main(){
    return 0;
}

GameBoard createGameBoard(int n) {
    GameBoard game;
    game.size = n;
    game.board = new char* [n + 1];
    for (int i = 1; i <= n; i++) {
        game.board[i] = new char[n + 1];
        for (int j = 1; j <= n; j++) {
            game.board[i][j] = ' ';
        }
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int randomRowUser, randomColUser, randomRowComputer, randomColComputer;

   //random 
    /*do {
        randomRowUser = rand() % n + 1;
        randomColUser = rand() % n + 1;
        randomRowComputer = rand() % n + 1;
        randomColComputer = rand() % n + 1;
    } while ((randomRowUser == randomRowComputer && randomColUser == randomColComputer));

    game.board[randomRowUser][randomColUser] = 'B';
    game.board[randomRowComputer][randomColComputer] = 'R';*/
    
    if (n % 2 == 0) {
        game.board[n / 2 + 1][n / 2] = 'B';
        game.board[n / 2][n / 2 + 1] = 'R';
    }
    else {
        game.board[n / 2 + 1][n / 2] = 'B';
        game.board[n / 2 + 1][n / 2 + 1] = 'R';

    }

    return game;
}