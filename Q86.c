// Day 86 - Question 1: Square Root using Binary Search
// Binary Search on the range [0, n] to find the integer square root.
// Use long long to avoid overflow when computing mid * mid.

#include <stdio.h>

int mySqrt(int n) {
    if (n == 0) return 0;

    int low = 1, high = n;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (mid * mid == n)
            return (int)mid;
        else if (mid * mid < n) {
            ans = (int)mid;
            low = (int)mid + 1;
        } else {
            high = (int)mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", mySqrt(n));

    return 0;
}
