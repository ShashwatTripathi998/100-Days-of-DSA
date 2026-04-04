// Day 62 - Question 1: Graph Representation Using Adjacency List
// Represent a graph using an array of lists.
// Each index i stores a list of vertices adjacent to i.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* addEdge(struct Node* head, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = head;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->vertex);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[101];
    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u] = addEdge(adj[u], v);
        adj[v] = addEdge(adj[v], u); // For undirected graph
    }

    // Print adjacency list
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        printList(adj[i]);
    }

    return 0;
}
