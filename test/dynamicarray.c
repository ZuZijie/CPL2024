#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 6;
    // 分配内存：每行 2 个整数，总共 n 行
    int (*arr)[2] = (int (*)[2])malloc(n * sizeof(int[2]));
    
    // 检查内存分配是否成功
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 初始化数组元素为 0
    for (int i = 0; i < n; i++) {
        arr[i][0] = 0; // 第 1 列
        arr[i][1] = 0; // 第 2 列
    }

    // 打印数组元素
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

    // 释放动态分配的内存
    free(arr);

    return 0;
}
