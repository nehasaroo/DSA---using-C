#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

int isfull() {
    return top == SIZE - 1;
}

int isempty() {
    return top == -1;
}

void push(int value) {
    if (isfull()) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed into the stack\n", value);
    }
}

void pop() {
    if (isempty()) {
        printf("Stack underflow! Nothing to pop\n");
    } else {
        printf("%d popped from the stack\n", stack[top--]);
    }
}

void peek() {
    if (isempty()) {
        printf("Stack is empty, no top element\n");
    } else {
        printf("Top element of stack is %d\n", stack[top]);
    }
}

void display() {
    if (isempty()) {
        printf("Stack is empty, nothing to display\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
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
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
