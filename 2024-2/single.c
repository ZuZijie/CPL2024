#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005

int main() {
    int n;
    scanf("%d", &n);
    int a[MAX_SIZE] = {0};
    int count[MAX_SIZE] = {0}; // 用于存储元素出现次数

    for (int i = 0; i < 2 * n - 1; i++) {
        scanf("%d", &a[i]);
        count[a[i]]++; // 计数
    }

    for (int i = 0; i < 2 * n - 1; i++) {
        if (count[a[i]] == 1) { // 如果出现次数为1
            printf("%d\n", a[i]);
        }
    }

    return 0;
}
