#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

int main()
{
    char exp[100];
    int i;
    int balanced = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            top++;
            stack[top] = exp[i];
        }

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (top == -1)
            {
                balanced = 0;
                break;
            }

            if ((exp[i] == ')' && stack[top] != '(') ||
                (exp[i] == ']' && stack[top] != '[') ||
                (exp[i] == '}' && stack[top] != '{'))
            {
                balanced = 0;
                break;
            }

            top--;
        }
    }

    if (top != -1)
        balanced = 0;

    if (balanced)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}