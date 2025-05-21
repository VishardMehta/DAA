#include <iostream>
#include <vector>
using namespace std;

string lcs(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string res = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            res = a[i-1] + res;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    return res;
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    string ans = lcs(s1, s2);
    cout << "Longest Common Subsequence = " << ans << endl;

    return 0;
}
