#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define OFFSET 500   // to handle negative indices

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
struct Node* queue[MAX];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

// Build tree
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

// Structure to store node + HD
struct Pair {
    struct Node* node;
    int hd;
};

// BFS Queue for vertical traversal
struct Pair q[MAX];
int f = 0, r = -1;

// Vertical order traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // 2D array to store columns
    int cols[1000][100];
    int count[1000] = {0};

    // Initialize queue
    f = 0; r = -1;
    q[++r] = (struct Pair){root, 0};

    int minHD = 0, maxHD = 0;

    while (f <= r) {
        struct Pair temp = q[f++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        int index = hd + OFFSET;

        cols[index][count[index]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            q[++r] = (struct Pair){node->left, hd - 1};

        if (node->right)
            q[++r] = (struct Pair){node->right, hd + 1};
    }

    // Print columns from leftmost to rightmost
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + OFFSET;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", cols[idx][j]);
        }
        printf("\n");
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

    verticalOrder(root);

    return 0;
}
