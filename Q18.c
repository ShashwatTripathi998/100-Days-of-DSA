//Problem: Given an array of integers, rotate the array to the right by k positions.
#include <stdio.h>

// Function to reverse part of array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;

    // Read size
    scanf("%d", &n);

    int arr[n];

    // Read elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    // Step 1: Reverse whole array
    reverse(arr, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(arr, k, n - 1);

    // Print rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}