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
};

#endif 