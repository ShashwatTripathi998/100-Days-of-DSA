// Day 61 - Question 1: Graph Representation Using Adjacency Matrix
// Represent a graph using a 2D array (matrix).
// If there is an edge between vertex i and j, matrix[i][j] = 1, otherwise 0.

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 1-based indexing for vertices
    int adj[101][101];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    // Print adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", adj[i][j]);
            if (j < n) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
