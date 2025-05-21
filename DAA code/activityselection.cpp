#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct act {
    int s, f;
};

bool cmp(act a, act b) {
    return a.f < b.f;
}

void select_act(int s[], int f[], int n) {
    vector<act> a(n);
    for (int i = 0; i < n; i++) {
        a[i].s = s[i];
        a[i].f = f[i];
    }

    sort(a.begin(), a.end(), cmp);

    cout << "selected: ";
    int end = a[0].f;
    cout << "(" << a[0].s << "," << a[0].f << ") ";
    
    for (int i = 1; i < n; i++) {
        if (a[i].s >= end) {
            cout << "(" << a[i].s << "," << a[i].f << ") ";
            end = a[i].f;
        }
    }
    cout << endl;
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);

    select_act(s, f, n);

    return 0;
}