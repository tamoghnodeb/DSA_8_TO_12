#include <stdio.h>

int tree[100];

void create()
{
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter value for node %d: ", i);
        scanf("%d", &tree[i]);
    }
}

void display()
{
    int i;

    printf("Tree elements are:\n");

    for (i = 1; i <= 10; i++)
    {
        if (tree[i] != 0)
            printf("%d ", tree[i]);
    }
}

int main()
{
    create();
    display();

    return 0;
}