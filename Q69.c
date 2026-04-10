// Day 69 - Question 1: Dijkstra's Algorithm (Shortest Path)
// Find shortest path from source to all vertices in graph with non-negative weights.
// Greedy approach. Doesn't work for negative weights.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 1000000000

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n;

void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        // Find unvisited vertex with minimum distance
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (dist[u] == INF) break;
        visited[u] = 1;

        // Relax adjacent edges
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    int m, src;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected
    }

    scanf("%d", &src);
    dijkstra(src);

    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
