#include <stdio.h>

#define MAX 1000

int main() {
    int n, m, top = -1, stack[MAX];

    // Read number of elements to push
    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
        printf("Pushed %d onto stack.\n", stack[top]);
    }

    // Number of pops
    printf("Enter number of pops: ");
    scanf("%d", &m);

    // Pop m times
    for (int i = 0; i < m; i++) {
        if (top == -1) {
            printf("Stack Underflow! Cannot pop.\n");
        } else {
            printf("Popped %d from stack.\n", stack[top]);
            top--;
        }
    }

    // Display remaining elements
    printf("Remaining stack (top to bottom): ");
    if (top == -1) {
        printf("Stack is empty.");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d", stack[i]);
            if (i != 0) printf(" ");
        }
    }

    return 0;
}
