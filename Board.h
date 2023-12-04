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

    bool hasWon(bool player) {
        for (int i = 0; i < size; i++) {
            int column = 0; 
            for (int j = 0; j < size; j++) {
                if (grid[j][i] == player) {
                    column++;
                } else {
                    column = 0;
                }
                if (column == 4) {
                    return true;
                }
            }
        }
        
        for (int i  = 0; i < size; i++) {
            int row = 0;
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == player) {
                    row++;
                } else {
                    row = 0;
                }
                if (row == 4) {
                    return true;
                }
            }
        }
    }

    bool play(int column) {
        if (grid[0][column] != -1 || column > 6 || column < 0) {
            return false;
        }

        for (int i = size - 1; i > 0; i--) {
            if (grid[i][column] == -1) {
                grid[i][column] = playerTurn;
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

std::ostream& operator<<(std::ostream& os, const Board& game) {
    os << "   ";
    for (int j = 0; j < game.size; j++){
        os << " " << j << "  ";
    }
    os << std::endl;
    os << "   ";
    for (int j = 0; j < game.size; j++){
        os << "--- ";
    }
    os << std::endl;
    for (int i = 0; i < game.size; i++){
        os << i << " ";
        for (int j = 0; j < game.size; j++){
            char c = ' ';
            if (game.grid[i][j] == 0){
                c = 'X';
            }
            else if (game.grid[i][j] == 1){
                c = 'O';
            }
            os << "| " << c << " ";
            if (j == game.size - 1) os << "|";
        }
        os << std::endl << "   ";
        for (int j = 0; j < game.size; j++){
            os << "--- ";
        }
        os << std::endl;
    }

    return os;
}

#endif 
