#include <stdio.h>
#include <ctype.h>

void formatSentence(char *input, char *output) {
    int i = 0, j = 0;
    int firstWord = 1; // 用于标记是否是第一个单词

    while (input[i] != '\0') {
        if (isupper(input[i])) { // 检查大写字母
            if (!firstWord) {
                output[j++] = ' '; // 如果不是第一个单词，在前面添加空格
            }
            firstWord = 0; // 第一个单词标记结束
            output[j++] = tolower(input[i]); // 转为小写，存入输出数组
        } else { // 小写字母直接存入
            output[j++] = input[i];
        }
        i++;
    }
    output[j] = '\0'; // 添加字符串结束符
}

int main() {
    char input[1024];   // 输入字符串
    char output[1024];  // 输出字符串

    printf("Enter the input string: ");
    scanf("%s", input); // 读取输入字符串

    formatSentence(input, output);

    // 首字母改为大写
    if (output[0] != '\0') {
        output[0] = toupper(output[0]);
    }

    printf("Formatted sentence: %s\n", output);

    return 0;
}
