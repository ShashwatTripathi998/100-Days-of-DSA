#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Linked list node (stack)
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push onto stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop from stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Check if a token is an operator
int isOperator(char* token) {
    return (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0);
}

int main() {
    char expr[200];
    fgets(expr, sizeof(expr), stdin);

    char* token = strtok(expr, " ");

    while (token != NULL) {

        if (!isOperator(token)) {
            // Operand → convert to int and push
            push(atoi(token));
        } 
        else {
            // Operator → pop 2 operands
            int b = pop();
            int a = pop();
            int res;

            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            push(res);  // push result back
        }

        token = strtok(NULL, " ");
    }

    // Final result
    printf("%d", pop());

    return 0;
}
