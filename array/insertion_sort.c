#include <stdio.h>

int main() {
    int a[100], n, i, j, temp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    printf("The sorted elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
