// Day 70 - Question 1: Bellman-Ford Algorithm
// Computes shortest paths from source to all vertices.
// Works with negative weights. Detects negative cycles.
// Relax all edges V-1 times. If changes happen on Vth relaxation, negative cycle exists.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 1000000000

int main() {
    int V, E, S;
    scanf("%d %d %d", &V, &E, &S);

    int edges[MAX][3]; // u, v, weight
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    int dist[MAX];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[S] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycle (Nth relaxation)
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}
