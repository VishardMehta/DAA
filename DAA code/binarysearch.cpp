#include <iostream>
using namespace std;

int bin_search(int arr[], int l, int r, int x) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == x) return mid;
    if (x < arr[mid]) return bin_search(arr, l, mid - 1, x);
    return bin_search(arr, mid + 1, r, x);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 23;
    int idx = bin_search(arr, 0, n - 1, x);

    if (idx != -1)
        cout << "found at index " << idx << endl;
    else
        cout << "not found" << endl;

    return 0;
}