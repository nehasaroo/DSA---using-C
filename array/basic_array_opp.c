#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int arr[MAX];
int size = 0;


void insertStart(int value);
void insertEnd(int value);
void insertPos(int value, int pos);
void deleteStart();
void deleteEnd();
void deletePos(int pos);
void display();

int isFull() {
    return size == MAX;
}

int isEmpty() {
    return size == 0;
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n----- ARRAY MENU -----\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Start\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertStart(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPos(value, pos);
                break;

            case 4:
                deleteStart();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}



void insertStart(int value) {
    if (isFull()) {
        printf("Array is FULL\n");
        return;
    }

    for (int i = size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = value;
    size++;
}

void insertEnd(int value) {
    if (isFull()) {
        printf("Array is FULL\n");
        return;
    }
    arr[size++] = value;
}

void insertPos(int value, int pos) {
    if (isFull()) {
        printf("Array is FULL\n");
        return;
    }
    if (pos <= 0 || pos > size + 1) {
        printf("Invalid position\n");
        return;
    }

    for (int i = size - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = value;
    size++;
}

void deleteStart() {
    if (isEmpty()) {
        printf("Array is EMPTY\n");
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void deleteEnd() {
    if (isEmpty()) {
        printf("Array is EMPTY\n");
        return;
    }
    size--;
}

void deletePos(int pos) {
    if (isEmpty()) {
        printf("Array is EMPTY\n");
        return;
    }
    if (pos <= 0 || pos > size) {
        printf("Invalid position\n");
        return;
    }

    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void display() {
    if (isEmpty()) {
        printf("Array is EMPTY\n");
        return;
    }

    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}
