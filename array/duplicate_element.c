#include<stdio.h>

int main() {
    int i, j, f = 0, arr[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {

        if (arr[i] == -1)  
            continue;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {

                if (f == 0) {
                    printf("The duplicate elements are:\n");
                }

                printf("%d ", arr[i]);
                f = 1;
                arr[j] = -1;   
                break;
            }
        }
    }

    if (f == 0) {
        printf("No duplicate elements are there!\n");
    }

    return 0;
}