#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// 检查选项是否有效
int IsValidOption(char a, char rule[], int lengthOfRule) {
    for (int i = 0; i < lengthOfRule; i++) {
        if (a == rule[i]) {
            return 1;
        }
    }
    return 0;
}

// 检查选项是否需要值
int IsOptionRequireValue(char a, char rule[], int lengthOfRule) {
    for (int i = 0; i < lengthOfRule; i++) {
        if (a == rule[i]) {
            return (i + 1 < lengthOfRule && rule[i + 1] == ':');
        }
    }
    return 0;
}
    char token[102500][1025];
int main() {
    char rule[10240], name[1025];

    char *optionValues[10240] = {0};  
    int tokenLength = 0;
    scanf("%s", rule);
    scanf("%s", name);
    while (tokenLength < 102500 && scanf("%s", token[tokenLength]) != EOF) {
        tokenLength++;
    }

    if (tokenLength == 0) {
        printf("%s\n", name);
        return 0;
    }
    if (token[tokenLength - 1][0] == '-') {
        int ruleLength = strlen(rule);
        for (int i = 0; i < ruleLength; i++) {
            if (rule[i] == token[tokenLength - 1][1] && IsOptionRequireValue(rule[i], rule, ruleLength)) {
                printf("%s: option requires an argument -- '%c'\n", name, token[tokenLength - 1][1]);
                return 1;
            }
        }
    }
    int ruleLength = strlen(rule);
    for (int i = 0; i < tokenLength; i++) {
        if (token[i][0] == '-') {  
            if (strlen(token[i]) < 2 || !IsValidOption(token[i][1], rule, ruleLength)) {
                printf("%s: invalid option -- '%c'\n", name, token[i][1]);
                return 2;
            }
            for (int j = 0; j < ruleLength; j++) {
                if (token[i][1] == rule[j] && IsOptionRequireValue(rule[j], rule, ruleLength)) {
                    if (i + 1 >= tokenLength || token[i + 1][0] == '-') {
                        printf("%s: option requires an argument -- '%c'\n", name, token[i][1]);
                        return 1;
                    }
                    optionValues[(int)token[i][1]] = token[i + 1];  
                    i++;  
                }
            }
        }
    }

    printf("%s\n", name);
    for (int i = 0; i < ruleLength; i++) {
        if (rule[i] != ':' && optionValues[(int)rule[i]] != NULL) {
            printf("-%c=%s\n", rule[i], optionValues[(int)rule[i]]);
        } else if (rule[i] != ':' && optionValues[(int)rule[i]] == NULL) {
            printf("-%c\n", rule[i]);
        }
    }

    return 0;
}
