#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check if empty
int empty() {
    return (front == -1);
}

// Check if full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Push front
void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = x;
}

// Push back
void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Get front
void get_front() {
    if (empty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[front]);
    }
}

// Get back
void get_back() {
    if (empty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[rear]);
    }
}

// Size
void size() {
    if (empty()) {
        printf("0\n");
    } else if (rear >= front) {
        printf("%d\n", rear - front + 1);
    } else {
        printf("%d\n", MAX - front + rear + 1);
    }
}

// Display deque
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Reverse deque
void reverse() {
    if (empty()) return;

    int i = front, j = rear;
    while (i != j && (i + MAX - 1) % MAX != j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

// Clear deque
void clear() {
    front = rear = -1;
}

// Sort deque (simple bubble sort)
void sort() {
    if (empty()) return;

    int n;
    if (rear >= front)
        n = rear - front + 1;
    else
        n = MAX - front + rear + 1;

    int tempArr[MAX];
    int i = front;

    for (int k = 0; k < n; k++) {
        tempArr[k] = deque[i];
        i = (i + 1) % MAX;
    }

    // Bubble sort
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - a - 1; b++) {
            if (tempArr[b] > tempArr[b + 1]) {
                int t = tempArr[b];
                tempArr[b] = tempArr[b + 1];
                tempArr[b + 1] = t;
            }
        }
    }

    // Copy back
    front = 0;
    rear = n - 1;
    for (int k = 0; k < n; k++) {
        deque[k] = tempArr[k];
    }
}

int main() {
    // Example usage
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();     // 5 10 20 30

    pop_front();   // removes 5
    pop_back();    // removes 30

    display();     // 10 20

    push_front(1);
    push_back(50);

    display();     // 1 10 20 50

    sort();
    display();     // 1 10 20 50

    reverse();
    display();     // 50 20 10 1

    size();        // 4

    clear();
    size();        // 0

    return 0;
}
