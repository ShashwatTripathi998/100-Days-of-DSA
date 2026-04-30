// Day 97 - Question 1: Meeting Rooms Scheduling
// Find the minimum number of meeting rooms required.
// Sort meetings by start time. Use a min-heap to track meeting end times.
// For each meeting, if earliest ending meeting ends before current starts, reuse the room.

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* m1 = *(int**)a;
    int* m2 = *(int**)b;
    return m1[0] - m2[0];
}

void swap(int* heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapifyUp(int* heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int* heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(heap, index, smallest);
        heapifyDown(heap, size, smallest);
    }
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

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    heap[heapSize++] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (heap[0] <= intervals[i][0]) {
            // Reuse room: replace earliest ending time
            heap[0] = intervals[i][1];
            heapifyDown(heap, heapSize, 0);
        } else {
            // Need new room
            heap[heapSize] = intervals[i][1];
            heapifyUp(heap, heapSize);
            heapSize++;
        }
    }

    printf("%d\n", heapSize);

    free(heap);
    for (int i = 0; i < n; i++) free(intervals[i]);
    free(intervals);

    return 0;
}
