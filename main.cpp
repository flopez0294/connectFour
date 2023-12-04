#include <iostream> 
#include "Board.h"

using namespace std;

int main() {
    Board game;
    while (!game.done) {
        system("clear");
        std::cout << game << std::endl;

        int x;

        std::cout << std::endl;
        std::cout << "Enter move for (" << (!game.playerTurn ? "X" : "O") << "): ";
        std::cin >> x;

        game.play();
    }

    system("clear");
    std::cout << game << std::endl;
    std::cout << std::endl;
    if (game.hasWon(0)){
        std::cout << "Player X has won" << std::endl;
    }
    else if (game.hasWon(1)){
        std::cout << "Player O has won" << std::endl;
    }
    else {
        std::cout << "It's a tie" << std::endl;
    }

    return 0; 
}