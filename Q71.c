// Day 71 - Question 1: Hash Table Using Quadratic Probing
// Quadratic probing resolves collisions using i^2 jumps.
// Steps: Compute hash index using key % table_size.
// If collision occurs, move using quadratic probing formula.

#include <stdio.h>

#define SIZE 7

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
}

void insert(int key) {
    int h = key % SIZE;
    int i = 0;

    while (i < SIZE) {
        int index = (h + i * i) % SIZE;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
    printf("Table is full, cannot insert %d\n", key);
}

int search(int key) {
    int h = key % SIZE;

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (table[index] == key)
            return index;

        if (table[index] == -1)
            return -1;
    }
    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("[%d]: empty\n", i);
        else
            printf("[%d]: %d\n", i, table[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    init();

    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(key);
    }

    display();

    int searchKey;
    scanf("%d", &searchKey);
    int result = search(searchKey);
    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}
