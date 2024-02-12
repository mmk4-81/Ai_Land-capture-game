#include <iostream>
#include <climits>
#include <ctime>
using namespace std;

struct GameBoard
{
    char **board;
    int size;
};
int boardSize;

GameBoard createGameBoard(int n);
void destroyGameBoard(GameBoard &game);
void printBoard(const GameBoard &game);
bool isBoardFull(const GameBoard& game);
bool isMovvalueid(const GameBoard& game, int row, int col, char userMarker);
bool hasValidMove(const GameBoard& game, char userMarker);

void playgame(GameBoard &game, char userMarker, char computerMarker);

int main()
{
    cout << "Enter the size of the game board: ";
    cin >> boardSize;

    GameBoard game = createGameBoard(boardSize);

    char userMarker = 'B';
    char computerMarker = 'R';

    printBoard(game);
    playgame(game, userMarker, computerMarker);
    destroyGameBoard(game);
    return 0;
}

GameBoard createGameBoard(int n)
{
    GameBoard game;
    game.size = n;
    game.board = new char *[n + 1];
    for (int i = 1; i <= n; i++)
    {
        game.board[i] = new char[n + 1];
        for (int j = 1; j <= n; j++)
        {
            game.board[i][j] = ' ';
        }
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int randomRowUser, randomColUser, randomRowComputer, randomColComputer;

    // random
    /*do {
        randomRowUser = rand() % n + 1;
        randomColUser = rand() % n + 1;
        randomRowComputer = rand() % n + 1;
        randomColComputer = rand() % n + 1;
    } while ((randomRowUser == randomRowComputer && randomColUser == randomColComputer));

    game.board[randomRowUser][randomColUser] = 'B';
    game.board[randomRowComputer][randomColComputer] = 'R';*/

    if (n % 2 == 0)
    {
        game.board[n / 2 + 1][n / 2] = 'B';
        game.board[n / 2][n / 2 + 1] = 'R';
    }
    else
    {
        game.board[n / 2 + 1][n / 2] = 'B';
        game.board[n / 2 + 1][n / 2 + 1] = 'R';
    }

    return game;
}

void destroyGameBoard(GameBoard &game)
{
    for (int i = 1; i <= game.size; i++)
    {
        delete[] game.board[i];
    }
    delete[] game.board;
}

void printBoard(const GameBoard &game)
{
    cout << endl;
    for (int i = 1; i <= game.size; i++)
    {
        for (int j = 1; j <= game.size; j++)
        {
            cout << "+---";
        }
        cout << "+" << endl;

        for (int j = 1; j <= game.size; j++)
        {
            cout << "| ";
            if (game.board[i][j] == 'B')
            {
                cout << "\033[1;34mB\033[0m";
            }
            else if (game.board[i][j] == 'R')
            {
                cout << "\033[1;31mR\033[0m";
            }
            else
            {
                cout << " ";
            }
            cout << " ";
        }
        cout << "|" << endl;
    }

    for (int j = 1; j <= game.size; j++)
    {
        cout << "+---";
    }
    cout << "+" << endl;
}

bool isBoardFull(const GameBoard& game) {
    for (int i = 1; i <= game.size; i++) {
        for (int j = 1; j <= game.size; j++) {
            if (game.board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool isMovvalueid(const GameBoard& game, int row, int col, char Marker) {
    if (row < 1 || row > game.size || col < 1 || col > game.size) {
        return false;
    }
   
}

bool hasValidMove(const GameBoard& game, char userMarker) {
    for (int i = 1; i <= game.size; ++i) {
        for (int j = 1; j <= game.size; ++j) {
            
        }
    }
    return false;
}

void playgame(GameBoard &game, char userMarker, char computerMarker)
{

    char marker = userMarker;
    char opmarker = computerMarker;
    while (!isBoardFull(game)) {

    }
}