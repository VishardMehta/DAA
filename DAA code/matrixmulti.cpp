#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print_order(int i, int j, vector<vector<int>> &bracket, int &name) {
    if (i == j) {
        cout << "M" << name++;
        return;
    }
    cout << "(";
    print_order(i, bracket[i][j], bracket, name);
    print_order(bracket[i][j] + 1, j, bracket, name);
    cout << ")";
}

int matrix_chain(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> split(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    int name = 1;
    cout << "Efficient way: ";
    print_order(1, n-1, split, name);
    cout << endl;
    return dp[1][n-1];
}

int main() {
    int arr[] = {2, 1, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min_mult = matrix_chain(arr, n);
    cout << "Multiplications performed = " << min_mult << endl;

    return 0;
}
