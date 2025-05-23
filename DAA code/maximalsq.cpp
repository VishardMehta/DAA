#include <iostream>
#include <vector>
using namespace std;

int max_square(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++)
        dp[i][0] = mat[i][0], ans = max(ans, dp[i][0]);

    for (int j = 0; j < m; j++)
        dp[0][j] = mat[0][j], ans = max(ans, dp[0][j]);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 1)
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    int side = max_square(mat);
    cout << "Maximum length of square sub-matrix with all 1s: " << side << endl;

    return 0;
}
