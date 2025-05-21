#include <iostream>
using namespace std;

bool is_safe(int mat[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (mat[row][x] == num || mat[x][col] == num)
            return false;
    }

    int start_row = row - row % 3, start_col = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (mat[start_row + i][start_col + j] == num)
                return false;

    return true;
}

bool solve(int mat[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (mat[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_safe(mat, row, col, num)) {
                        mat[row][col] = num;
                        if (solve(mat))
                            return true;
                        mat[row][col] = 0;
                    }
                }
                return false; // no valid number
            }
        }
    }
    return true; // filled all cells
}

void print(int mat[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solve(mat)) {
        cout << "Solved Sudoku:\n";
        print(mat);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
