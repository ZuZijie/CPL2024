#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int IsValidOption(char a, char rule[], int lengthOfRule) {
    for (int i = 0; i < lengthOfRule; i++) {
        if (a == rule[i]) {
            return 1;
        }
    }
    return 0;
}

int IsOptionRequireValue(char a, char rule[], int lengthOfRule) {
    for (int i = 0; i < lengthOfRule; i++) {
        if (a == rule[i]) {
            return (i + 1 < lengthOfRule && rule[i + 1] == ':');
        }
    }
    return 0;
}

int main() {
    char rule[102400], token[102500][1025], name[1025];
    char *optionValues[256] = {0};
    int tokenLength = 0;

    scanf("%s", rule);
    scanf("%s", name);

    while (scanf("%s", token[tokenLength]) != EOF) {
        tokenLength++;
    }

    if (tokenLength == 0) {
        printf("%s\n", name);
        return 0;
    }

    int ruleLength = strlen(rule);
    if (token[tokenLength - 1][0] == '-') {
        for (int i = 0; i < ruleLength; i++) {
            if (rule[i] == token[tokenLength - 1][1] && IsOptionRequireValue(rule[i], rule, ruleLength)) {
                printf("%s: option requires an argument -- '%c'\n", name, token[tokenLength - 1][1]);
                return 1;
            }
        }
    }

    for (int i = 0; i < tokenLength; i++) {
        if (token[i][0] == '-') {
            if (!IsValidOption(token[i][1], rule, ruleLength)) {
                printf("%s: invalid option -- '%c'\n", name, token[i][1]);
                return 2;
            }
            if (IsOptionRequireValue(token[i][1], rule, ruleLength)) {
                if (i + 1 < tokenLength && token[i + 1][0] != '-') {
                    optionValues[(int)token[i][1]] = token[i + 1];
                    i++;
                } else {
                    printf("%s: option requires an argument -- '%c'\n", name, token[i][1]);
                    return 1;
                }
            } else {
                optionValues[(int)token[i][1]] = NULL;
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
