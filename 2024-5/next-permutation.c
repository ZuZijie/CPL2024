#include <stdio.h>

void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void next(int* arr, int n) {
    int m = n - 1;
    while (m > 0 && arr[m - 1] >= arr[m]) {
        m--;
    }

    if (m == 0) {
        reverse(arr, 0, n - 1);
        return;
    }

    int Pk = arr[m - 1];

    int k = n - 1;
    while (arr[k] <= Pk) {
        k--;
    }

    int temp = arr[m - 1];
    arr[m - 1] = arr[k];
    arr[k] = temp;


    reverse(arr, m, n - 1);
}

int main() {
    int arr[2000], n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    next(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

