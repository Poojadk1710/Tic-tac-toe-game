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
