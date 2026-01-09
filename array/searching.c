#include <stdio.h>

int main() {
    int a[50], size, key, i, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < size; i++) {
        if (a[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Element not found");
    }

    return 0;
}
