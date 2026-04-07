// Day 65 - Question 1: Cycle Detection in Undirected Graph (DFS)
// If we encounter a visited node that is not the parent of the current node,
// a cycle exists. Time Complexity: O(V + E)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            } else if (i != parent) {
                return 1; // Cycle detected
            }
        }
    }
    return 0;
}

int isCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    if (isCycle())
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
