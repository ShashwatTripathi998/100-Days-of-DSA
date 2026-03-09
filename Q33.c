#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack operations
void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

// Function to define operator precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    // Input
    scanf("%s", infix);

    // Convert
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If operand → add to postfix
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(' → push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')' → pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); // Remove '('
        }
        // Operator encountered
        else {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    // Output
    printf("%s", postfix);

    return 0;
}
