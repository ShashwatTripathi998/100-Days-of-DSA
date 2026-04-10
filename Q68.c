// Day 68 - Question 1: Topological Sort (Kahn's BFS Algorithm)
// Uses in-degree concept. Nodes with in-degree 0 are added to queue.
// Decrease in-degree of neighbors. Also detects cycles (if result size < V).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

void topoSort() {
    int front = 0, rear = 0;

    // Add all nodes with in-degree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int topo[MAX];
    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (count != n) {
        printf("Cycle detected - Topological sort not possible\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed graph
        indegree[v]++;
    }

    topoSort();

    return 0;
}
