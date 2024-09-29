#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int arr[], int n, int ascending) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int ascSwaps = bubbleSort(arr, n, 1);
    int descSwaps = bubbleSort(arr, n, 0);

    int minSwaps = ascSwaps < descSwaps ? ascSwaps : descSwaps;
    printf("Minimum swaps required: %d\n", minSwaps);

    return 0;
}
