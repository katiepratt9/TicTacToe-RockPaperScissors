#pragma once
#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H
#include <iostream>
#include <string>
#include <algorithm> // for transform
#include <time.h>
using namespace std;
    class RockPaperScissor
    {
    public:
        int randNum;//picks a random number representing rock paper or scissors
        const string RPS[3]= {"Rock", "Paper", "Scissors"};
        string playerChoice = "";
        string computerChoice = "not working";
        string endgame = "no";
        bool invalid = true; 
        int pPoints = 0;
        int cPoints = 0;
        void shoot();
        string chooseThrow();
    };
    string RockPaperScissor::chooseThrow()
    {
        int N = 3;
        randNum = rand() % N;
        return RPS[randNum];
    }
    void RockPaperScissor::shoot()
    {
        srand(time(NULL)); 
        while (endgame == "no")
        {
            while (playerChoice == "")
            {
                cout << '\n' << "enter your rock paper or scissors: ";
                cin >> playerChoice;
                transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::tolower);
                if (playerChoice == "rock") 
                    playerChoice = "Rock";
                else if (playerChoice == "paper") 
                    playerChoice = "Paper";
                else if (playerChoice == "scissors") 
                    playerChoice = "Scissors";
                else {
                    playerChoice = "";
                    cout << "invalid choice";
                }
            }
            computerChoice = chooseThrow();
            cout << '\n' << "You choose " << playerChoice << " The Computer threw " << computerChoice;
            if (playerChoice == "Rock" && computerChoice == "Scissors")
            {
                cout << '\n' << "Rock crushes Scissors, YOU WIN!";
                pPoints++;
            }
            else if (playerChoice == "Rock" && computerChoice == "Paper")
            {
                cout << '\n' << "Paper covers Rock, YOU LOSE!";
                cPoints++;
            }
            else if (playerChoice == "Paper" && computerChoice == "Rock")
            {
                cout << '\n' << "Paper covers Rock, YOU WIN!";
                pPoints++;
            }
            else if (playerChoice == "Paper" && computerChoice == "Scissors")
            {
                cout << '\n' << "Scissors cuts Paper, YOU LOSE!";
                cPoints++;
            }
            else if (playerChoice == "Scissors" && computerChoice == "Paper")
            {
                cout << '\n' << "Scissors cuts Paper, YOU WIN!";
                pPoints++;
            }
            else if (playerChoice == "Scissors" && computerChoice == "Rock")
            {
                cout << '\n' << "Rock crushes Scissors, YOU LOSE!";
                cPoints++;
            }
            else
            {
                cout << '\n' << "It's a Tie!";
            }

            cout << '\n' << "computer has " << cPoints << " you have " << pPoints;
            
            if (cPoints > pPoints)
            {
                cout << " Computer is winning";
            }
            else if(cPoints < pPoints)
            {
                cout << " Player is winning";
            }
            else 
            {
                cout << " No One is winning";
            }

            while (invalid == true)
            {
                cout << '\n' << "Enter no to continue playing or yes to endgame: ";
                cin >> endgame;
                if (endgame != "yes" && endgame != "no")
                {
                    cout << "invalid choice";
                }
                else
                {
                    invalid = false;
                }
            }
            
            playerChoice = "";
            computerChoice = "not working";
            invalid = true;
        }
        
        if (cPoints > pPoints)
        {
            cout << "Computer Won! ";
        }
        else
        {
            cout << "Player Won! ";
        }
        cout << '\n' << "Thanks for playing!";
       
    }
#endif /* ROCKPAPERSCISSORS_H */
