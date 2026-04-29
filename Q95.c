// Day 95 - Question 1: Bucket Sort (Float Values 0-1)
// Bucket Sort works well when numbers are uniformly distributed over a range.
// Steps: Create n empty buckets, put each element into bucket index = n * value,
// sort individual buckets (insertion sort), concatenate all buckets.

#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    float** buckets = (float**)malloc(n * sizeof(float*));
    int* bucketSizes = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(n * arr[i]);
        if (idx >= n) idx = n - 1; // Handle edge case for value = 1.0
        buckets[idx][bucketSizes[idx]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    // Concatenate all buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
