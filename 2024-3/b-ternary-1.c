#include "stdio.h"
#include "ctype.h"
#include "math.h"
#include "string.h"

int main()
{
    int n, ans[10000] = {0};  // 结果数组，初始化为0
    char input[16];  // 用于存储输入字符串，最多15个字符+终止符

    scanf("%d", &n);  // 读取测试用例数量
    getchar();  // 读取并丢弃换行符

    for (int i = 0; i < n; i++)
    {
        scanf("%15s", input);  // 读取最多15个字符的字符串
        int length = strlen(input);  // 获取输入字符串的长度
        int isValid = 1;  // 用于标记输入是否有效

        // 检查是否有无效字符
        for (int j = 0; j < length; j++) {
            if (input[j] != '0' && input[j] != 'Z' && input[j] != '1') {
                ans[i] = 1919810;  // 标记为无效输入
                isValid = 0;
                break;  // 立即跳出无效字符检测
            }
        }

        if (isValid) {
            ans[i] = 0;  // 初始化结果为0
            int power = 1;  // 从最低位开始，初始化幂次为1
            for (int j = length - 1; j >= 0; j--) {
                if (input[j] == '1') ans[i] += power;  // 对 '1' 加上对应的值
                if (input[j] == 'Z') ans[i] -= power;  // 对 'Z' 减去对应的值
                power *= 3;  // 每一位的权重乘以3
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        if (ans[i] == 1919810)
            printf("Radix Error\n");
        else
            printf("%d\n", ans[i]);
    }

    return 0;
}
