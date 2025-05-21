#include <iostream>
using namespace std;

int max_sub_sum(int arr[], int n) {
    int max_so_far = arr[0], curr = arr[0];
    for (int i = 1; i < n; i++) {
        curr = max(arr[i], curr + arr[i]);
        max_so_far = max(max_so_far, curr);
    }
    return max_so_far;
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "max sum is " << max_sub_sum(arr, n) << endl;

    return 0;
}