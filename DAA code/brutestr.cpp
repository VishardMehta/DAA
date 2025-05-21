#include <iostream>
#include <string>
using namespace std;

void bruteForceSearch(const string& txt, const string& pat) {
    int n = txt.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == m) {
            cout << "Pattern found at index " << i + 1 << "\n"; // 1-based indexing
        }
    }
}

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    bruteForceSearch(txt, pat);

    return 0;
}
