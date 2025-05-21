#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
void buildLPS(const string& pat, vector<int>& lps) {
    int len = 0;  // length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0; // lps[0] is always 0

    while (i < (int)pat.size()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void kmpSearch(const string& txt, const string& pat) {
    int n = (int)txt.size();
    int m = (int)pat.size();

    vector<int> lps(m);
    buildLPS(pat, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++; j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << (i - j + 1) << "\n"; // 1-based index
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    kmpSearch(txt, pat);

    return 0;
}
