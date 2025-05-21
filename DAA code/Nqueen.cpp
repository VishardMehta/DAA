#include <iostream>
#include <vector>
using namespace std;

bool safe(int row, int col, vector<int> &pos) {
    for (int i = 0; i < row; i++) {
        if (pos[i] == col || abs(pos[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solve(int row, int n, vector<int> &pos) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (safe(row, col, pos)) {
            pos[row] = col;
            if (solve(row + 1, n, pos))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<int> pos(n, -1); // pos[i] = column of queen in row i

    if (solve(0, n, pos)) {
        cout << "[ ";
        for (int i = 0; i < n; i++)
            cout << pos[i] + 1 << (i == n - 1 ? " " : ", ");
        cout << "]" << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
