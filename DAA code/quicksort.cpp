#include <iostream>
using namespace std;

int part(int arr[], int l, int r) {
    int piv = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < piv) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quick_sort(int arr[], int l, int r) {
    if (l < r) {
        int p = part(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

int main() {
    int arr[] = {4, 2, 6, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}