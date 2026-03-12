#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX) return;
    pq[size++] = x;
}

// Find index of minimum element
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Delete highest priority element (smallest)
void delete() {
    int minIndex = findMinIndex();

    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);

    // Shift elements to remove it
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek highest priority element
void peek() {
    int minIndex = findMinIndex();

    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);
}

int main() {
    int n;
    scanf("%d", &n);

    char operation[10];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(value);
        }
        else if (strcmp(operation, "delete") == 0) {
            delete();
        }
        else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
