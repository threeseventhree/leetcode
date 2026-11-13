#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 9; i++) {
        bool seen[9] = {false};
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;

            int index = board[i][j] - '1';
            if (seen[index]) return false;
            seen[index] = true;
        }
    } // Each row must contain the digits 1-9 without repetition.

    for (int i = 0; i < 9; i++) {
        bool seen[9] = {false};
        for (int j = 0; j < 9; j++) {
            if (board[j][i] == '.') continue;

            int index = board[j][i] - '1';
            if (seen[index]) return false;
            seen[index] = true;
        }
    } // Each column must contain the digits 1-9 without repetition.

    for (int box = 0; box < 9; box++) {
        bool seen[9] = {false};
        int start_row = (box / 3) * 3;
        int start_col = (box % 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(board[start_row + i][start_col + j] == '.') continue;

                int index = board[start_row + i][start_col + j] - '1';
                if (seen[index]) return false;
                seen[index] = true;
            }
        }
    } // Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    return true;
}
// Time to solve: 13min 34sec

