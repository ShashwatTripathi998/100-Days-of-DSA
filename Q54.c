#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for building tree
struct Node* queue[1000];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    // Reset queue
    front = 0;
    rear = -1;

    enqueue(root);

    int leftToRight = 1;

    while (front <= rear) {
        int levelSize = rear - front + 1;
        int temp[1000];

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = dequeue();

            // Store based on direction
            if (leftToRight)
                temp[i] = curr->data;
            else
                temp[levelSize - 1 - i] = curr->data;

            if (curr->left)
                enqueue(curr->left);

            if (curr->right)
                enqueue(curr->right);
        }

        // Print current level
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", temp[i]);
        }

        // Toggle direction
        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
