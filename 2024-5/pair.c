#include "stdio.h"

int quick_sort(int *a, int low, int high) {
    int i = low;
    int j = high;
    int key = a[(low + high) / 2]; 

    while (i <= j) {
        while (a[i] < key) {
            i++;
        }
        while (a[j] > key) {
            j--;
        }
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j) quick_sort(a, low, j);
    if (i < high) quick_sort(a, i, high);
    return 0;
}

int main() {
    int n, m, t, min = -1;
    int arr1[10000006], arr2[10000006];
    scanf("%d %d %d", &n, &m, &t);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    quick_sort(arr2, 0, m - 1);
    for (int i = 0; i < n; i++) {
        if (arr1[i] > t) break;
        int remaining = t - arr1[i];
        int left = 0, right = m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr2[mid] <= remaining) {
                left = mid + 1; 
            } else {
                right = mid - 1;
            }
        }
        if (right >= 0) {
            int sum = arr1[i] + arr2[right];
            if (min == -1 || (t - sum < min)) {
                min = t - sum;
            }
        }
    }

    printf("%d\n", min);
    return 0;
}
