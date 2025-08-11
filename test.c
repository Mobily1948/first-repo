#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int len = 5;

void init(int arr[]) {
    for(int i = 0; i < len; i++)
        arr[i] = rand() % 10;
}

void display(int arr[]) {
    for(int i = 0; i < len; i++)
        printf("%d -> ", arr[i]);
    printf("NULL\n");
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];

    for(int i = 0; i < n1; i++)
        arr1[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    while(i < n1)
        arr[k++] = arr1[i++];
    while(j < n2)
        arr[k++] = arr2[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

        // puoi stampare qui per vedere lo stato dell’array ad ogni passo:
        // display(arr);
    }
}

int main() {
    srand(time(NULL));

    int arr[len];
    init(arr);

    printf("Array iniziale: ");
    display(arr);

    mergeSort(arr, 0, len - 1);

    printf("Array ordinato: ");
    display(arr);

    return 0;
}

