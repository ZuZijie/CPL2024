#include "stdio.h"

int main() {
    int n1, n2, n3;
    int num = 0, sum = 0;

    scanf("%d", &num);
    
    while (1) {
        int h = num / 100;
        int t = (num / 10) % 10;
        int o = num % 10;

        // 设定n1, n2, n3的初始值
        n1 = n2 = n3 = 0;

        // 排序逻辑
        if (h > t && t > o) { n1 = h; n2 = t; n3 = o; }
        else if (h > o && o > t) { n1 = h; n2 = o; n3 = t; }
        else if (t > h && h > o) { n1 = t; n2 = h; n3 = o; }
        else if (t > o && t > h) { n1 = t; n2 = o; n3 = h; }
        else if (o > h && h > t) { n1 = o; n2 = h; n3 = t; }
        else if (o > t && t > h) { n1 = o; n2 = t; n3 = h; }

        int num2 = 100 * n1 + 10 * n2 + n3;
        int num3 = 100 * n3 + 10 * n2 + n1;

        if (num - num2 + num3 > 0)
            sum += num - num2 + num3;

        num = num2 - num3;

        if (num == 495) 
            break; // 修改为 break 以退出循环
    }
    
    printf("%d", sum);
    return 0;
}
