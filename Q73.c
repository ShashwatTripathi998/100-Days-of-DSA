// Day 73 - Question 1: First Non-Repeating Character
// Use hashing to count the frequency of each character.
// Steps: Traverse string once and store frequency.
// Traverse again and return first character with frequency 1.

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    int found = 0;

    scanf("%s", s);

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("$\n");

    return 0;
}
