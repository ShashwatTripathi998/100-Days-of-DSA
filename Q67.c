// Day 67 - Question 1: Topological Sort (DFS)
// Linear ordering of vertices such that for every edge u -> v, u appears before v.
// Only for DAGs. Use a stack to store the sort.
// Key: Push to stack after visiting all children.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = node; // Push after visiting all children
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed graph
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}
