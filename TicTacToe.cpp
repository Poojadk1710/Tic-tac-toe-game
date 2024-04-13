/*********************************************************
* Name       :  Pooja Kulkarni
* Class      :  CSCI 2312 Section 001
* Due Date   :  04/12/2024
*********************************************************/

/*********************************************************
* Summary: This file includes the implementation for TicTacToe.cpp.
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

#include "TicTacToe.h"
#include <cstdlib>
#include <ctime>

// Constructor for the TicTacToe class
TicTacToe::TicTacToe(int s) : playerTurn(true) {
    while (s < 3) {         // Check if the provided size is less than 3
        std::cerr << "Error: Minimum board size is 3x3. Please enter a valid size: ";
        std::cin >> s;
    }
    size = s;   // Set the size of the board to the provided size

    // Dynamically allocate memory for the game board based on the size
    board = new char*[size];
    for (int i = 0; i < size; ++i) {
        board[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            board[i][j] = '-';      // Initialize all cells of the board to empty
        }
    }
}

// Destructor for the TicTacToe class
TicTacToe::~TicTacToe() {
    // Deallocate memory for the game board
    for (int i = 0; i < size; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

// Function to draw the current state of the game board
void TicTacToe::drawBoard() const {
     // Loop through each cell of the board and print its contents
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;  // Move to the next row after printing each row of the board
    }
}

// Function to check if a specific cell on board is occupied
bool TicTacToe::isFull(int x, int y) const {
    return board[x][y] != '-';  // Check if the cell is not empty
}

// Function to check if a player has won the game
bool TicTacToe::checkWin(char player) const {
    // Check rows
    for (int i = 0; i < size; ++i) {            // Check rows for a win
        bool win = true;
        for (int j = 0; j < size; ++j) {
            if (board[i][j] != player) {
                win = false;                // If any cell in the row is not occupied by the player, no win
                break;
            }
        }
        if (win)            // If all cells in the row are occupied by the player, win
        return true;
    }

    // Check columns for win
    for (int j = 0; j < size; ++j) {
        bool win = true;
        for (int i = 0; i < size; ++i) {
            if (board[i][j] != player) {
                win = false;        // If any cell in the column is not occupied by the player, no win
                break;
            }
        }
        if (win) return true;       // If all cells in the column are occupied by the player, win
    }

    // Check diagonals for win
    bool diagonal1 = true;
    bool diagonal2 = true;
    for (int i = 0; i < size; ++i) {
        if (board[i][i] != player) {
            diagonal1 = false;   // If any cell in the main diagonal is not occupied by the player, no win
        }
        if (board[i][size - i - 1] != player) {
            diagonal2 = false;  // If any cell in the secondary diagonal is not occupied by the player, no win
        }
    }
    if (diagonal1 || diagonal2) return true;    // If all cells in any diagonal are occupied by the player, win

    return false;    // If no win condition is met, return false
}

// Function to check if the game has ended in a draw
bool TicTacToe::checkDraw() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == '-') return false; // If any empty cell is found, game is not a draw
        }
    }
    return true;
}

void TicTacToe::makeMove(int x, int y, char player) {
    board[x][y] = player;
}

void TicTacToe::playGame() {
    char currentPlayer = 'X'; // Player 1 starts
    while (!checkWin('X') && !checkWin('O') && !checkDraw()) {
        std::cout << "Current board:\n";
        drawBoard();
        std::cout << "Player's turn (" << currentPlayer << ").\n";
        int x, y;
        std::cout << "Enter row and column: ";
        std::cin >> x >> y;
        x--; // Adjust for 0-indexing
        y--; // Adjust for 0-indexing
        if (x >= 0 && x < size && y >= 0 && y < size && !isFull(x, y)) {
            makeMove(x, y, currentPlayer);
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }
    std::cout << "Game over!\n";
    drawBoard();
    if (checkWin('X')) {
        std::cout << "Player 1 (X) wins!\n";
    } else if (checkWin('O')) {
        std::cout << "Player 2 (O) wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }
}
