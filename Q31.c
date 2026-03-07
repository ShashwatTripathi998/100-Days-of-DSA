#include <stdio.h>

#define MAX 1000

int main()
{
    int n, top = -1, stack[MAX];
    scanf("%d", &n);

    while (n--)
    {
        int op, val;
        scanf("%d", &op);

        if (op == 1)
        { // PUSH
            scanf("%d", &val);
            stack[++top] = val;
        }

        else if (op == 2)
        { // POP
            if (top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("%d\n", stack[top--]);
            }
        }

        else if (op == 3)
        { // DISPLAY
            if (top == -1)
            {
                printf("\n");
            }
            else
            {
                for (int i = top; i >= 0; i--)
                {
                    printf("%d", stack[i]);
                    if (i != 0)
                        printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}
