// Day 98 - Question 1: Merge Overlapping Intervals
// Merge intervals by sorting them based on start time and then comparing
// each interval with the last merged one.
// Steps: Sort by start time, keep result array, merge overlapping intervals.

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* i1 = *(int**)a;
    int* i2 = *(int**)b;
    return i1[0] - i2[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int** intervals = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    qsort(intervals, n, sizeof(int*), compare);

    int** result = (int**)malloc(n * sizeof(int*));
    int idx = 0;

    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            // Overlapping: merge by extending end
            if (intervals[i][1] > result[idx][1])
                result[idx][1] = intervals[i][1];
        } else {
            // Non-overlapping: add new interval
            idx++;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
        }
    }

    int resultSize = idx + 1;
    for (int i = 0; i < resultSize; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) free(intervals[i]);
    free(intervals);
    for (int i = 0; i < resultSize; i++) free(result[i]);
    free(result);

    return 0;
}
