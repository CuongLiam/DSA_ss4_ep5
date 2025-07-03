#include <stdio.h>
#include <stdlib.h>

int binSearch(int *arr, int n, int key);

void bubbleSort(int *arr, int n);

int main(void) {
    int n;
    printf("n= ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("\n%d", arr[i]);
    }

    int key;
    printf("nhap so muon tim: ");
    scanf("%d", &key);

    if (binSearch(arr, n, key)) {
        printf("phan tu co trong mang");
    } else {
        printf("phan tu ko co trong mang");
    }

    free(arr);
    return 0;
}

int binSearch(int *arr, int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (key < arr[mid]) {
            high = mid - 1;
        } else if (key == arr[mid]) {
            // return mid;
            return 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

