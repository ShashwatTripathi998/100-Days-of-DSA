//  Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>

int main() {

    int n;

    // Read size of square matrix
    scanf("%d", &n);

    int matrix[n][n];

    // Read matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity condition
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // Diagonal elements must be 1
            if (i == j && matrix[i][j] != 1) {
                printf("Not an Identity Matrix");
                return 0;
            }

            // Non-diagonal elements must be 0
            if (i != j && matrix[i][j] != 0) {
                printf("Not an Identity Matrix");
                return 0;
            }
        }
    }

    // If all conditions satisfied
    printf("Identity Matrix");

    return 0;
}
