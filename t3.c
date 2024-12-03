#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int IsReserved(char *input) {
    char *reservedWords[] = { "const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto" };
    for (int i = 0; i < 16; i++) {
        if (strcmp(input, reservedWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
int IsOperator(char *input) {
    char *operators[] = { "+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<" };
    for (int i = 0; i < 11; i++) {
        if (strcmp(input, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
int IsIntegerorFloat(char *input) {
    int numofDot = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (input[i] == '.') {
            numofDot++;
        } else if (!isdigit(input[i])) {
            return -1; 
        }
    }

    if (numofDot > 1) {
        return -1; 
    }
    return (numofDot == 1) ? 2 : 1; 
}
int IsValidVariable(char *input) {
    int len = strlen(input);

    if (isdigit(input[0])) {
        return -1; 
    }

    for (int i = 0; i < len; i++) {
        if (!isalnum(input[i]) && input[i] != '_') {
            return -1; 
        }
    }

    return 1; 
}

    char inp[10000][10000]; 
    char ans[10000][10000]; 
int main() {

    int num = 0;          
    char s[1000];         

    while (scanf("%s", s) != EOF) {
        int len = strlen(s);
        int start = 0;

        for (int j = 0; j < len; j++) {
            if (s[j] == ';') {
 
                if (j > start) {
                    char temp[1000] = {0};
                    strncpy(temp, s + start, j - start);
                    temp[j - start] = '\0';
                    strcpy(inp[num++], temp);
                }


                inp[num][0] = ';';
                inp[num++][1] = '\0';
                start = j + 1;
            }
        }
        if (start < len) {
            char temp[1000] = {0};
            strcpy(temp, s + start);
            strcpy(inp[num++], temp);
        }
    }
    if (num == 0 || strcmp(inp[num - 1], ";") != 0) {
        printf("Compile Error\n");
        return 0;
    }
    for (int i = 0; i < num; i++) {
        if (strcmp(inp[i], ";") == 0) {
            strcpy(ans[i], "\n");
        } else if (IsReserved(inp[i])) {
            strcpy(ans[i], "reserved");
        } else if (IsOperator(inp[i])) {
            strcpy(ans[i], "operator");
        } else if (IsIntegerorFloat(inp[i]) == 1) {
            strcpy(ans[i], "integer");
        } else if (IsIntegerorFloat(inp[i]) == 2) {
            strcpy(ans[i], "float");
        } else if (IsValidVariable(inp[i]) == 1) {
            strcpy(ans[i], "variable");
        } else {
            printf("Compile Error\n");
            return 0;
        }
    }
    for (int i = 0; i < num; i++) {
        if (strcmp(ans[i], "\n") == 0) {
            printf("\n");
        } else {
            printf("%s ", ans[i]);
        }
    }

    return 0;
}
