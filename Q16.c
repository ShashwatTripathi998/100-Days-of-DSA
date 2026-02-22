// Given an array of integers, count the frequency of each distinct element and print the result.
#include <stdio.h>

int main() {
    int n;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for (int i = 0; i < n; i++) {
        int count = 1;

        // Skip already counted elements
        if (arr[i] == -999999)  
            continue;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -999999;  // Mark as counted
            }
        }

        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}