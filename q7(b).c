#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push()
{
    int x;

    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("Pushed successfully\n");
}

void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;
        printf("Popped: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top = %d\n", top->data);
}

void display()
{
    struct Node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}