// Day 82 - Question 1: Upper Bound & Lower Bound Implementation
// Lower Bound: Find the first index where arr[mid] >= x
// Upper Bound: Find the first index where arr[mid] > x
// Both run in O(log n) time.

#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, x;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    printf("%d %d\n", lowerBound(arr, n, x), upperBound(arr, n, x));

    return 0;
}
