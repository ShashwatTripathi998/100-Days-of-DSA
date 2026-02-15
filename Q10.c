// Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main() {

    char s[1000];

    // Input
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;

    // Two-pointer comparison
    while (left < right) {

        if (s[left] != s[right]) {
            printf("NO");
            return 0;
        }

        left++;
        right--;
    }

    // If no mismatch found
    printf("YES");

    return 0;
}