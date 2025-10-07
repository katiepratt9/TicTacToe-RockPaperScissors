#pragma once
#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H
#include <iostream>
#include <Vector>
using namespace std;
class Board
{
private:
    vector<char> board{
        'A','B','C',
        'D','E','F',
        'G','H','I'
    };
public:
    void printBoard();
    bool setBoardSpot(int,char);
    char getBoardSpot(int);
    char checkForWin();
    char checkVertWin();
    char checkHorzWin();
    char checkDiagWin();
    bool isSpotFree(int);
};

bool Board::isSpotFree(int index) {
    return board[index] != 'X' && board[index] != 'O';
}

void Board::printBoard()
{
    for (int i = 0; i < board.size(); ++i) {
        if (i % 3 == 0 && i != 0) 
        {
            cout << '\n';
            cout << "-------------";
            cout << '\n';
        }
        if (board[i] == 'O')
        {
            // Yellow for O
            cout << " \033[33m" << board[i] << "\033[0m | ";
        }
        else if (board[i] == 'X')
        {
            // Blue for X
            cout << " \033[34m" << board[i] << "\033[0m | ";
        }
        else
        {
            // Red for unused spots
            cout << " \033[31m" << board[i] << "\033[0m | ";
        }
    }
    cout << endl;
}
bool Board::setBoardSpot(int index, char who) 
{
    if (isSpotFree(index))
    {
        board[index] = who;
        return true;
    }
    return false;
}
char Board::getBoardSpot(int index)
{
    return board[index];
}
char Board::checkVertWin()
{
    char win = '?';
    if (board[0] == board[3] && board[3] == board[6])
    {
        win = board[0];
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        win = board[1];
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        win = board[2];
    }
    return win;
}
char Board::checkHorzWin()
{
    char win = '?';
    if (board[0] == board[1] && board[1] == board[2])
    {
        win = board[0];
    }
    else if (board[3] == board[4] && board[4] == board[5])
    {
        win = board[3];
    }
    else if (board[6] == board[7] && board[7] == board[8])
    {
        win = board[6];
    }
    return win;
}
char Board::checkDiagWin()
{
    char win = '?';
    if (board[0] == board[4] && board[4] == board[8])
    {
        win = board[0];
    }
    else if (board[2] == board[4] && board[4] == board[6])
    {
        win = board[2];
    }
    return win;
}
char Board::checkForWin() 
{
    char win = '?';
    win = checkVertWin();
    if (win != '?')
    {
        return win;
    }
    win = checkHorzWin();
    if (win != '?')
    {
        return win;
    }
    win = checkDiagWin();
    if (win != '?')
    {
        return win;
    }
    return win;
}
#endif 
