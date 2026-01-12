#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    return (rear == MAX - 1);
}

int isNull()
{
    return (front == -1 || front > rear);
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is FULL. Cannot enqueue %d\n", value);
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

void dequeue()
{
    if (isNull())
    {
        printf("Queue is EMPTY. Nothing to dequeue.\n");
    }
    else
    {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void peek()
{
    if (isNull())
    {
        printf("Queue is EMPTY. No front element.\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

void display()
{
    if (isNull())
    {
        printf("Queue is EMPTY.\n");
    }
    else
    {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- QUEUE MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Full\n");
        printf("6. Check if Null (Empty)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                if (isFull())
                {
                    printf("Queue is FULL.\n");
                }
                else
                {
                    printf("Queue is NOT full.\n");
                }
                break;

            case 6:
                if (isNull())
                {
                    printf("Queue is NULL (EMPTY).\n");
                }
                else
                {
                    printf("Queue is NOT null.\n");
                }
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}