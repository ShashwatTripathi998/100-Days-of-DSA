#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    // Input number of elements
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    int front = 0;
    int size = n;

    // Perform dequeue operations
    for (int i = 0; i < m; i++) {
        if (size == 0) {
            break;
        }
        front = (front + 1) % n;  // circular move
        size--;
    }

    // Display elements from front to rear (circular)
    int count = size;
    int i = front;

    while (count--) {
        printf("%d ", queue[i]);
        i = (i + 1) % n;
    }

    free(queue);
    return 0;
}
