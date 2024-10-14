#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[6]={0};
    for(int i=0;i<6;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,6);
     for(int i=0;i<6;i++)
    {
        printf("%d  ",arr[i]  );
    }
    return 0;
}
