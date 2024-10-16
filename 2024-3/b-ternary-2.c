#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 判断输入是否是有效的十进制整数
int isValidDecimal(char *str) {
    if (*str == '-') str++;  // 跳过负号
    if (*str == '\0') return 0;  // 检查是否只有一个负号
    while (*str) {
        if (!isdigit(*str)) return 0;  // 只允许数字
        str++;
    }
    return 1;
}

// 将十进制整数转换为平衡三进制并存储到result中
void changeDecimal(int num, char *result) {
    if (num == 0) {
        strcpy(result, "0");
        return;
    }

    int n = abs(num);
    char temp[32];
    int index = 0;

    while (n != 0) {   // 把十进制转为平衡三进制
        int rem = n % 3;
        n = n / 3;
        if (rem == 2) {
            temp[index++] = 'Z';
            n++; // 向高位进位
        } else if (rem == 1) {
            temp[index++] = '1';
        } else {
            temp[index++] = '0';
        }
    }

    // 处理负数的符号变化，Z变1，1变Z
    if (num < 0) {
        for (int i = 0; i < index; i++) {
            if (temp[i] == '1') {
                temp[i] = 'Z';
            } else if (temp[i] == 'Z') {
                temp[i] = '1';
            }
        }
    }

    // 倒序输出结果
    for (int i = 0; i < index; i++) {
        result[i] = temp[index - 1 - i];
    }
    result[index] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);

    char input[16];
    char result[32];

    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        if (!isValidDecimal(input)) {
            printf("Radix Error\n");
            continue;
        }

        int num = atoi(input);
        changeDecimal(num, result);
        printf("%s\n", result);
    }

    return 0;
}
