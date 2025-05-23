#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item {
    int profit, weight;
};

bool cmp(item a, item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double frac_knapsack(vector<item> arr, int w) {
    sort(arr.begin(), arr.end(), cmp);
    double total = 0.0;

    cout << "Items taken (profit, weight):\n";

    for (auto it : arr) {
        if (w == 0) break;

        if (it.weight <= w) {
            total += it.profit;
            w -= it.weight;
            cout << "  Taken full item: (" << it.profit << ", " << it.weight << ")\n";
        } else {
            double fraction = (double)w / it.weight;
            total += it.profit * fraction;
            cout << "  Taken fraction " << fraction << " of item: (" << it.profit << ", " << it.weight << ")\n";
            w = 0;
        }
    }

    return total;
}

int main() {
    vector<item> arr = {{60, 10}, {100, 20}, {120, 30}};
    int w = 50;

    double ans = frac_knapsack(arr, w);
    cout << "Max profit: " << ans << endl;

    return 0;
}
