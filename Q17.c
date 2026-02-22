//Problem: Write a program to find the maximum and minimum values present in a given array of integers.
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

    // Assume first element is both min and max
    int min = arr[0];
    int max = arr[0];

    // Find min and max
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Print result
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}