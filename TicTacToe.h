/*********************************************************
* Name       :  Pooja Kulkarni
* Class      :  CSCI 2312 Section 001
* Due Date   :  04/12/2024
*********************************************************/

/*********************************************************
* Summary: This file includes the implementation for TicTacToe.h.
*
* Author: Pooja Kulkarni
* Student ID : 111024438
* Created: April 08, 2024
* Summary of Modifications [if applicable]:
*      April 08, 2024 - Initial implementation of TicTacToe game
*      April 11, 2024 - Completed implementation of all game functions
*      April 11, 2024 - Resolved bugs and successfully compiled the code
*      April 12, 2024 - Added comments and coding style to the code
*      April 12, 2024 - Conducted thorough testing and ensured functionality as per specifications
*      April 12, 2024 - Finalized documentation and submitted
*********************************************************/
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

class TicTacToe {
private:
    char** board;       // Pointer to 2D array to represent the game board
    int size;            // Size of the game board 
    bool playerTurn;    //track which player's turn

public:
    TicTacToe(int s);   // Constructor to initialize the game
    ~TicTacToe();       // Destructor 

    void drawBoard() const;     // Function to draw the current state of the game board
    bool isFull(int x, int y) const; // Function to check if a specific cell on the board is occupied
    bool checkWin(char player) const;       // Function to check if a player has won the game
    bool checkDraw() const;             // Function to check if the game has ended in a draw
    void makeMove(int x, int y, char player);       // Function to make a move on the game board
    void playGame();                // Function to start and play the game

};

#endif
