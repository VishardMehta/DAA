#include <iostream>
#include <algorithm>
using namespace std;

int find_platforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);

    int plat = 1, max_plat = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat++;
            i++;
        } else {
            plat--;
            j++;
        }
        max_plat = max(max_plat, plat);
    }
    return max_plat;
}

int main() {
    // converted times to 24-hour format in minutes
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "min platforms needed = " << find_platforms(arr, dep, n) << endl;
    return 0;
}