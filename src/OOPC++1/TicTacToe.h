#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
#include <time.h>
#include "TicTacToeBoard.h";
using namespace std;
class TicTacToe
{
public:
    Board board;
    bool validSpot = false;
    char playerChoice = 'B';
    char game = '?';
    char comp = 'O';
    bool compTurnTaken = false;
    char keepPlaying = 'W';
    int tieCount = 0;
    void playerTurn();
    void computerTurn();
    void Game();
    int canWin(int, int, int);
    int checkVertWin(char);
    int checkHorzWin(char);
    int checkDiagWin(char);
    int charToIndex(char);
};
void TicTacToe::Game()
{
    board.printBoard();
    while (game == '?' && tieCount < 8)
    {
        if (game == '?' && tieCount < 8)
        {
            cout << '\n';
            cout << "Computers turn...... " << '\n';
            cout << '\n';
            computerTurn();
            game = board.checkForWin();
            board.printBoard();
            tieCount++;
        }
        if (game == '?' && tieCount < 9)
        {
            cout << '\n';
            game = board.checkForWin();
            playerTurn();
            board.printBoard();
            game = board.checkForWin();
            tieCount++;
        }
    }
    if (game == 'X')
    {
        cout << "Player Wins!!!!";
    }
    else if (game == 'O')
    {
        cout << "Computer Wins!!!!";
    }
    else 
    {
        cout << "Its a Tie!!!!";
    }
    cout<< '\n';
    while (keepPlaying != 'N')
    {
        cout << "would you like to play again? Y or N: " << '\n';
        cin >> keepPlaying;
        if (keepPlaying == 'Y') 
        {
            Board newboard;
            board = newboard;
            validSpot = false;
            playerChoice = 'B';
            game = '?';
            compTurnTaken = false;
            tieCount = 0;
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            cout << '\n';
            Game();
        }
    }
}
void TicTacToe::playerTurn()
{
    validSpot = false;
    while (!validSpot)
    {
        cout << '\n' << "Enter the letter (A-I) where you want to go: ";
        cin >> playerChoice;
        int index = charToIndex(playerChoice);
        if (index != -1 && board.isSpotFree(index)) {
            board.setBoardSpot(index, 'X');
            validSpot = true;
        }
        else {
            cout << "Invalid spot. Please choose again.\n";
        }
    }
}

int TicTacToe::canWin(int vert, int horz, int diag)
{
    if (vert != -1)
    {
        return vert;
    }
    else if (horz != -1)
    {
        return horz;
    }
    else if (diag != -1)
    {
        return diag;
    }
    else 
    {
        return -1;
    }
}

int TicTacToe::checkVertWin(char type)
{
    // column 0
    if (board.getBoardSpot(0) == type && board.getBoardSpot(3) == type && board.isSpotFree(6)) 
        return 6;
    if (board.getBoardSpot(0) == type && board.getBoardSpot(6) == type && board.isSpotFree(3)) 
        return 3;
    if (board.getBoardSpot(3) == type && board.getBoardSpot(6) == type && board.isSpotFree(0)) 
        return 0;

    // column 1
    if (board.getBoardSpot(1) == type && board.getBoardSpot(4) == type && board.isSpotFree(7)) 
        return 7;
    if (board.getBoardSpot(1) == type && board.getBoardSpot(7) == type && board.isSpotFree(4)) 
        return 4;
    if (board.getBoardSpot(4) == type && board.getBoardSpot(7) == type && board.isSpotFree(1)) 
        return 1;

    // column 2
    if (board.getBoardSpot(2) == type && board.getBoardSpot(5) == type && board.isSpotFree(8)) 
        return 8;
    if (board.getBoardSpot(2) == type && board.getBoardSpot(8) == type && board.isSpotFree(5)) 
        return 5;
    if (board.getBoardSpot(5) == type && board.getBoardSpot(8) == type && board.isSpotFree(2)) 
        return 2;

    return -1;
}

int TicTacToe::checkHorzWin(char type)
{
    // row 0
    if (board.getBoardSpot(0) == type && board.getBoardSpot(1) == type && board.isSpotFree(2)) 
        return 2;
    if (board.getBoardSpot(0) == type && board.getBoardSpot(2) == type && board.isSpotFree(1)) 
        return 1;
    if (board.getBoardSpot(1) == type && board.getBoardSpot(2) == type && board.isSpotFree(0)) 
        return 0;

    // row 1
    if (board.getBoardSpot(3) == type && board.getBoardSpot(4) == type && board.isSpotFree(5))
        return 5;
    if (board.getBoardSpot(3) == type && board.getBoardSpot(5) == type && board.isSpotFree(4)) 
        return 4;
    if (board.getBoardSpot(4) == type && board.getBoardSpot(5) == type && board.isSpotFree(3)) 
        return 3;

    // row 2
    if (board.getBoardSpot(6) == type && board.getBoardSpot(7) == type && board.isSpotFree(8)) 
        return 8;
    if (board.getBoardSpot(6) == type && board.getBoardSpot(8) == type && board.isSpotFree(7)) 
        return 7;
    if (board.getBoardSpot(7) == type && board.getBoardSpot(8) == type && board.isSpotFree(6)) 
        return 6;

    return -1;
}

int TicTacToe::checkDiagWin(char type)
{
    // main diagonal
    if (board.getBoardSpot(0) == type && board.getBoardSpot(4) == type && board.isSpotFree(8)) 
        return 8;
    if (board.getBoardSpot(0) == type && board.getBoardSpot(8) == type && board.isSpotFree(4)) 
        return 4;
    if (board.getBoardSpot(4) == type && board.getBoardSpot(8) == type && board.isSpotFree(0)) 
        return 0;

    // anti diagonal
    if (board.getBoardSpot(2) == type && board.getBoardSpot(4) == type && board.isSpotFree(6)) 
        return 6;
    if (board.getBoardSpot(2) == type && board.getBoardSpot(6) == type && board.isSpotFree(4)) 
        return 4;
    if (board.getBoardSpot(4) == type && board.getBoardSpot(6) == type && board.isSpotFree(2)) 
        return 2;

    return -1;
}

void TicTacToe::computerTurn() 
{
    compTurnTaken = false;
    //Win if possible
    int vertc = checkVertWin('O');
    int horzc = checkHorzWin('O');
    int diagc = checkDiagWin('O');
    int wcVDH = canWin(vertc,horzc,diagc);

    int vertp = checkVertWin('X');
    int horzp = checkHorzWin('X');
    int diagp = checkDiagWin('X');
    int wpVDH = canWin(vertp, horzp, diagp);

    if (wcVDH != -1)
    {
        board.setBoardSpot(wcVDH, 'O');
        compTurnTaken = true;
    }
    //Block the opponent's winning move
    else if (wpVDH != -1)
    {
        board.setBoardSpot(wpVDH, 'O');
        compTurnTaken = true;
    }
    // Take the center if free
    else if (board.isSpotFree(4))
    {
        board.setBoardSpot(4, 'O');
        compTurnTaken = true;
    }
    // Take the opposite corner
    else if (board.getBoardSpot(0) == 'X' && board.isSpotFree(8))
    {
        board.setBoardSpot(8, 'O');
        compTurnTaken = true;
    }
    else if (board.getBoardSpot(2) == 'X' && board.isSpotFree(6))
    {
        board.setBoardSpot(6, 'O');
        compTurnTaken = true;
    }
    else if (board.getBoardSpot(6) == 'X' && board.isSpotFree(2))
    {
        board.setBoardSpot(2, 'O');
        compTurnTaken = true;
    }
    else if (board.getBoardSpot(8) != 'X' && board.isSpotFree(0))
    {
        board.setBoardSpot(0, 'O');
        compTurnTaken = true;
    }
    // Take any corner
    else if (board.isSpotFree(0))
    {
        board.setBoardSpot(0, 'O');
        compTurnTaken = true;
    }
    else if (board.isSpotFree(2))
    {
        board.setBoardSpot(2, 'O');
        compTurnTaken = true;
    }
    else if (board.isSpotFree(6))
    {
        board.setBoardSpot(6, 'O');
        compTurnTaken = true;
    }
    else if (board.isSpotFree(8))
    {
        board.setBoardSpot(8, 'O');
        compTurnTaken = true;
    }
    // Take any side
    else if (board.isSpotFree(1))
    {
        board.setBoardSpot(1, 'O');
        compTurnTaken = true;
    }
    else if (board.isSpotFree(3))
    {
        board.setBoardSpot(3, 'O');
        compTurnTaken = true;
    }
    else if (board.isSpotFree(5))
    {
        board.setBoardSpot(5, 'O');
        compTurnTaken = true;
    }
    else if (board.isSpotFree(7))
    {
        board.setBoardSpot(7, 'O');
        compTurnTaken = true;
    }
}

int TicTacToe::charToIndex(char pos) {
    pos = toupper(pos); // make input case-insensitive
    if (pos >= 'A' && pos <= 'I') {
        return pos - 'A';
    }
    return -1; // invalid input
}
#endif 
