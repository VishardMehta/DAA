#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4, W = 7;
    int p[] = {5, 3, 8, 6}; // profit
    int w[] = {2, 3, 4, 5}; // weight

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // build dp table
    for (int i = 1; i <= n; i++) {
        for (int wt = 0; wt <= W; wt++) {
            if (w[i-1] <= wt) {
                dp[i][wt] = max(dp[i-1][wt], p[i-1] + dp[i-1][wt - w[i-1]]);
            } else {
                dp[i][wt] = dp[i-1][wt];
            }
        }
    }

    // backtrack to find selected items
    int wt = W;
    vector<int> items;
    for (int i = n; i > 0 && wt > 0; i--) {
        if (dp[i][wt] != dp[i-1][wt]) {
            items.push_back(i); // 1-based indexing
            wt -= w[i-1];
        }
    }

    // output
    cout << "Items selected: ";
    for (int i = items.size()-1; i >= 0; i--) {
        cout << "Item " << items[i];
        if (i != 0) cout << " and ";
    }
    cout << "\nMaximum profit: " << dp[n][W] << endl;

    return 0;
}
