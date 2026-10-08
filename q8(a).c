#include <stdio.h>

int queue[5];
int front = -1, rear = -1;

void enqueue()
{
    int x;

    if(rear == 4)
        printf("Queue is full\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Deleted: %d\n", queue[front]);
        front++;
    }
}

void peek()
{
    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else
        printf("Front: %d\n", queue[front]);
}

void display()
{
    int i;

    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);

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
            default: printf("Invalid choice\n");
        }
    }
}