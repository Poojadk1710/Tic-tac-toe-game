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
