#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      
    int j = mid + 1;   
    int k = left;      

   
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    
    while (j <= right) {
        temp[k++] = arr[j++];
    }

   
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}


void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

       
        if (arr[mid] <= arr[mid + 1])
            return;

        merge(arr, temp, left, mid, right);
    }
}


int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    if (arr == NULL || temp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, temp, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    free(temp);

    return 0;
}