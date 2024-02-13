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
bool isBoardFull(const GameBoard &game);
bool isCellEmpty(const GameBoard &game, int row, int col);
bool isMovvalueid(const GameBoard &game, int row, int col, char userMarker);
bool hasValidMove(const GameBoard &game, char userMarker);
void markCell(GameBoard &game, int row, int col, char marker);
bool makeMove(GameBoard &game, int row, int col, char userMarker);
void computerMove(GameBoard &game, char computerMarker, char userMarker);
int maxvalue(GameBoard& game, int depth, int alpha, int beta, char userMarker, char computerMarker);
int minvalue(GameBoard& game, int depth, int alpha, int beta, char userMarker, char computerMarker);
int minmax(GameBoard& game, int depth, int alpha, int beta, bool isMax, char userMarker, char computerMarker);

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
bool isBoardFull(const GameBoard &game)
{
    for (int i = 1; i <= game.size; i++)
    {
        for (int j = 1; j <= game.size; j++)
        {
            if (game.board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
bool isCellEmpty(const GameBoard &game, int row, int col)
{
    return game.board[row][col] == ' ';
}
bool isMovvalueid(const GameBoard &game, int row, int col, char Marker)
{
    if (row < 1 || row > game.size || col < 1 || col > game.size)
    {
        return false;
    }
    return isCellEmpty(game, row, col) && ((row - 1 >= 1 && game.board[row - 1][col] == Marker) ||
                                           (row + 1 <= game.size && game.board[row + 1][col] == Marker) ||
                                           (col - 1 >= 1 && game.board[row][col - 1] == Marker) ||
                                           (col + 1 <= game.size && game.board[row][col + 1] == Marker));
}
bool hasValidMove(const GameBoard &game, char userMarker)
{
    for (int i = 1; i <= game.size; ++i)
    {
        for (int j = 1; j <= game.size; ++j)
        {
            if (isMovvalueid(game, i, j, userMarker))
            {
                return true;
            }
        }
    }
    return false;
}
void markCell(GameBoard &game, int row, int col, char marker)
{
    game.board[row][col] = marker;
}
bool makeMove(GameBoard &game, int row, int col, char userMarker)

{
    if (isMovvalueid(game, row, col, userMarker))
    {
        markCell(game, row, col, userMarker);
        return true;
    }
    return false;
}
int minmax(GameBoard& game, int depth, int alpha, int beta, bool isMax, char userMarker, char computerMarker) {
    if (isMax) {
        // return maxvalue(game, depth, alpha, beta, userMarker, computerMarker);
    }
    else {
        // return minvalue(game, depth, alpha, beta, userMarker, computerMarker);
    }
}
int maxvalue(GameBoard& game, int depth, int alpha, int beta, char userMarker, char computerMarker) {
    

    int maxvalue = INT_MIN;
    for (int i = 1; i <= game.size; i++) {
        for (int j = 1; j <= game.size; j++) {
            if (isMovvalueid(game, i, j, computerMarker)) {
                markCell(game, i, j, computerMarker);
                int value = minmax(game, depth - 1, alpha, beta, false, userMarker, computerMarker);
                markCell(game, i, j, ' ');
                maxvalue = max(maxvalue, value);
                alpha = max(alpha, maxvalue);
                if (beta <= alpha)
                    break;
            }
        }
    }
    return maxvalue;
}
int minvalue(GameBoard& game, int depth, int alpha, int beta, char userMarker, char computerMarker) {


    int minvalue = INT_MAX;
    for (int i = 1; i <= game.size; i++) {
        for (int j = 1; j <= game.size; j++) {
            if (isMovvalueid(game, i, j, userMarker)) {
                markCell(game, i, j, userMarker);
                int value = minmax(game, depth - 1, alpha, beta, true, userMarker, computerMarker);
                markCell(game, i, j, ' ');
                minvalue = min(minvalue, value);
                beta = min(beta, minvalue);
                if (beta <= alpha)
                    break;
            }
        }
    }
    return minvalue;
}
void computerMove(GameBoard &game, char computerMarker, char userMarker)
{
    int bestMove = INT_MIN;
    int besti, bestj;
    int alpha = INT_MIN;
    int beta = INT_MAX;

    for (int i = 1; i <= game.size; i++)
    {
        for (int j = 1; j <= game.size; j++)
        {
            if (isMovvalueid(game, i, j, computerMarker))
            {
                markCell(game, i, j, computerMarker);
            int moveValue = minmax(game, 9, alpha, beta, false, userMarker, computerMarker);
                markCell(game, i, j, ' ');

                if (moveValue >= bestMove) {
                    bestMove = moveValue;
                    besti = i;
                    bestj = j;
                }
            }
        }
    }

    markCell(game, besti, bestj, computerMarker);
    cout << "\nComputer moved to row " << besti << ", column " << bestj << "." << endl;
    printBoard(game);
}

void playgame(GameBoard &game, char userMarker, char computerMarker)
{

    char marker = userMarker;
    char opmarker = computerMarker;
    while (!isBoardFull(game))
    {
        if (hasValidMove(game, marker))
        {
            if (marker == userMarker)
            {
                cout << "\nit's your turn \n\n";
                int row, col;

                cout << "Enter the row(1 ,2 , ... n): ";
                cin >> row;

                cout << "Enter the col(1 ,2 , ... n): ";
                cin >> col;
                if (makeMove(game, row, col, marker))
                {
                    printBoard(game);
                    marker = computerMarker;
                    opmarker = userMarker;
                }
                else
                {
                    cout << "\nInvalid move! Try again." << endl;
                }
            }
            else
            {
                cout << "\nIt's computer's turn\n\n";
                computerMove(game, computerMarker, userMarker);
                marker = userMarker;
                opmarker = computerMarker;
            }
        }
    }
}