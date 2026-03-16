#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Rotate linked list right by k
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int n = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    k = k % n;
    int steps = n - k;

    struct Node* newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, value, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}