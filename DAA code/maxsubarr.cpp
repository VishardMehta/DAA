#include <iostream>
using namespace std;

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

int cross_sum(int arr[], int l, int m, int r) {
    int left_sum = -1e9, sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    int right_sum = -1e9;
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int max_sub(int arr[], int l, int r) {
    if (l == r) return arr[l];

    int m = (l + r) / 2;

    int left = max_sub(arr, l, m);
    int right = max_sub(arr, m + 1, r);
    int cross = cross_sum(arr, l, m, r);

    return max3(left, right, cross);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "max sum is " << max_sub(arr, 0, n - 1) << endl;

    return 0;
}