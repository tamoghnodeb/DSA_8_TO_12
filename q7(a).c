#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", val);
        return;
    }

    stack[++top] = val;

    printf("Pushed %d into the stack.\n", val);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("Popped %d from the stack.\n", stack[top--]);
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack (Top to Bottom): ");

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Stack Menu (Array) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top)\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again!\n");
        }
    }

    return 0;
}