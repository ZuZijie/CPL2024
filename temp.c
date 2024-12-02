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

char rule[10240], token[102500][1025];
char *optionValues[1280]; // Array of pointers to store option values

int main() {
    char name[1025];
    int tokenLength = 0;
    scanf("%s", rule);
    scanf("%s", name);

    while (scanf("%s", token[tokenLength]) != EOF) {
        if (tokenLength < 102500) {
            tokenLength++;
        } 
    }

    if (tokenLength == 0) {
        printf("%s\n", name);
        return 0;
    }

    if (tokenLength > 0 && token[tokenLength - 1][0] == '-') {
        int ruleLength = strlen(rule);
        for (int i = 0; i < ruleLength; i++) {
            if (rule[i] == token[tokenLength - 1][1] && IsOptionRequireValue(rule[i], rule, ruleLength)) {
                printf("%s: option requires an argument -- '%c'\n", name, token[tokenLength - 1][1]);
                return -1;
            }
        }
    }

    int ruleLength = strlen(rule);
    for (int i = 0; i < tokenLength; i++) {
        if (token[i][0] == '-') {
            if (!IsValidOption(token[i][1], rule, ruleLength)) {
                printf("%s:invalid option -- '%c'\n", name, token[i][1]);
                return -2;
            }
            for (int j = 0; j < ruleLength; j++) {
                if (token[i][1] == rule[j] && IsOptionRequireValue(rule[j], rule, ruleLength)) {
                    if (i + 1 >= tokenLength || token[i + 1][0] == '-') {
                        printf("%s:option requires an argument -- '%c'\n", name, token[i][1]);
                        return -1;
                    }
                    if (j < 1280) { 
                        optionValues[j] = token[i + 1];
                    } 
                    i++; 
                }
            }
        }
    }

    printf("%s\n", name);
    for (int i = 0; i < tokenLength; i++) {
        if (token[i][0] == '-') {
            for (int j = 0; j < ruleLength; j++) {
                if (token[i][1] == rule[j]) {
                    if (optionValues[j] != NULL) {
                        printf("%s=%s\n", token[i] + 1, optionValues[j]);
                    } else {
                        printf("%s\n", token[i] + 1); 
                    }
                }
            }
        }
    }

    return 0;
}
