#include <iostream>
#include <string>
using namespace std;

#define d 256      // Number of characters in input alphabet
#define q 101      // A prime number for modulo in hashing

void rabinKarp(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text window
    int h = 1;

    // The value of h would be "pow(d, m-1)%q"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first text window
    for (i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current text window and pattern
        if (p == t) {
            // Check characters one by one
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i + 1 << "\n"; // 1-based index
        }

        // Calculate hash value for next window of text
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            // We might get negative value of t, convert it to positive
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    rabinKarp(txt, pat);

    return 0;
}
