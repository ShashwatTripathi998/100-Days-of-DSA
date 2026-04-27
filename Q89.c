// Day 89 - Question 1: Allocate Minimum Pages
// Binary Search on the maximum pages a student can be assigned.
// Search range: [max(pages), sum(pages)]
// Greedy check: assign books to students until adding next book exceeds mid.

#include <stdio.h>

int isFeasible(int pages[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + pages[i] > maxPages) {
            students++;
            currentSum = pages[i];

            if (students > m)
                return 0;
        } else {
            currentSum += pages[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        if (pages[i] > low)
            low = pages[i];
        high += pages[i];
    }

    if (n < m) {
        printf("-1\n");
        return 0;
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(pages, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}
