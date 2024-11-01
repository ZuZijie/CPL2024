#include <stdio.h>
#include "paixv.c"
extern void bubbleSort(int arr [],int n);
 // 确保有这个声明

int main()
{
    int arr[6] = {1, 1, 4, 5, 1, 4};
    bubbleSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]); // 添加空格
    }
    printf("\n"); // 最后换行
    return 0;
}
