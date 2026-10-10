#include "tictactoe.h"
#include "scores.h"
#include <iostream>

using namespace std;

void displayBoard(char board[3][3])
{
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "\n";
}

bool checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

void playTicTacToe(string playerName)
{
    char board[3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char currentPlayer = 'X';
    int position;

    cout << "\n--- Tic-Tac-Toe ---\n";
    cout << playerName << " = X\n";
    cout << "Computer = O\n";

    while (true)
    {
        displayBoard(board);

        if (currentPlayer == 'X')
        {
            cout << playerName << ", enter position (1-9): ";
            cin >> position;

            if (position < 1 || position > 9)
            {
                cout << "Invalid position. Please enter 1-9.\n";
                continue;
            }

            int row = (position - 1) / 3;
            int col = (position - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O')
            {
                cout << "Position already occupied. Try again.\n";
                continue;
            }

            board[row][col] = 'X';
        }
        else
        {
            bool moveMade = false;

            for (int i = 0; i < 3 && !moveMade; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] != 'X' &&
                        board[i][j] != 'O')
                    {
                        board[i][j] = 'O';
                        moveMade = true;
                        break;
                    }
                }
            }

            cout << "Computer made its move.\n";
        }

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);

            if (currentPlayer == 'X')
            {
                cout << "Congratulations " << playerName << "! You won!\n";

                GameRecord record;
                record.gameName = "Tic-Tac-Toe";
                record.playerName = playerName;
                record.score = 10;
                record.result = "Win";

                recordGame(record);
            }
            else
            {
                cout << "Computer won. Better luck next time!\n";

                GameRecord record;
                record.gameName = "Tic-Tac-Toe";
                record.playerName = playerName;
                record.score = 0;
                record.result = "Loss";

                recordGame(record);
            }

            break;
        }

        if (checkDraw(board))
        {
            displayBoard(board);

            cout << "The game is a draw!\n";

            GameRecord record;
            record.gameName = "Tic-Tac-Toe";
            record.playerName = playerName;
            record.score = 5;
            record.result = "Draw";

            recordGame(record);

            break;
        }

        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }
}