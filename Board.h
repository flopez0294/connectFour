#ifndef BOARD_H
#define BOARD_H

struct Board {
    int** grid;
    int size;
    int turnCount;
    bool playerTurn;
    bool done;
    
    Board() {
        size = 7;
        turnCount = 0; 
        grid = new int*[size];
        playerTurn = 0;
        done = 0;
        for (int i = 0; i < size; i++) {
            grid[i] = new int[size];
        }
    }

    bool play(int column) {
        if (grid[0][column] != -1 || column > 6 || column < 0) {
            return false;
        }

        for (int i = size - 1; i > 0; i--) {
            if (grid[i][column] == -1) {
                grid[i][column] = player;
                break;
            }
        }
        
        playerTurn = !playerTurn;
        turnCount++;

        if (turnCount == size*size) {
            done = true;
        } else if (hasWon(0) || hasWon(1)) {
            done = true;
        }
        return true;
    }
};

#endif 
