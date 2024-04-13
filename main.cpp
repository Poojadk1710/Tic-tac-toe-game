/*********************************************************
* Name       :  Pooja Kulkarni
* Class      :  CSCI 2312 Section 001
* Due Date   :  04/12/2024
*********************************************************/

/*********************************************************
* Summary: This file includes the implementation for main.cpp.
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

int main() {
    srand(time(0));
    int choice;
    do {
        std::cout << "Menu\n1. Play the game\n2. Exit\nEnter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                int size;
                std::cout << "Enter the size of the board (up to 10): ";
                std::cin >> size;
                TicTacToe game(size);
                game.playGame();
                break;
            }
            case 2:
                std::cout << "Thank you for playing my game ;)\n";
                break;
            default:
                std::cout << "Invalid choice!!! Please try again :(\n";
        }
    } while (choice != 2);

    return 0;
}
