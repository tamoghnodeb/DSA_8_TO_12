#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    int x;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        temp = front;

        printf("Deleted: %d\n", front->data);

        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);
    }
}

void peek()
{
    if(front == NULL)
        printf("Queue is empty\n");
    else
        printf("Front: %d\n", front->data);
}

void display()
{
    struct node *temp = front;

    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        while(temp != NULL)
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

    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}