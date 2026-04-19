// Day 80 - Question 1: Floyd-Warshall Algorithm
// Computes shortest paths between all pairs of vertices by progressively
// allowing each vertex as an intermediate node.
// Works for negative edges but not negative cycles.

#include <stdio.h>

#define INF 1000000000

int main() {
    int n;
    scanf("%d", &n);

    int dist[105][105];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == -1 && i != j)
                dist[i][j] = INF;
        }
    }

    // Floyd-Warshall: try each vertex as intermediate
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
