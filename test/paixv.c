#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // 外层循环控制每一轮排序的次数
    for (i = 0; i < n-1; i++) {
        // 内层循环进行元素之间的比较
        for (j = 0; j < n-i-1; j++) {
            // 如果前一个元素大于后一个元素，进行交换
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
