#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VARS 26
#define MAX_INPUT 256

typedef struct {
    char name;
    double value;
} Variable;

Variable variables[MAX_VARS];
int var_count = 0;
char error_message[MAX_INPUT] = {0};

// 辅助函数声明
void skip_spaces(char** str);
bool parse_expression(char** str, double* result);
bool parse_term(char** str, double* result);
bool parse_factor(char** str, double* result);
double parse_number(char** str);
bool handle_assignment(const char* input);

// 跳过空格
void skip_spaces(char** str) {
    while (isspace(**str)) (*str)++;
}

// 解析数字
double parse_number(char** str) {
    char* end;
    double num = strtod(*str, &end);
    *str = end;
    return num;
}

// 解析因子（数字、变量、括号表达式）
bool parse_factor(char** str, double* result) {
    skip_spaces(str);
    
    if (isdigit(**str) || **str == '.') {
        *result = parse_number(str);
        return true;
    }
    else if (**str == '(') {
        (*str)++;
        if (!parse_expression(str, result)) return false;
        skip_spaces(str);
        if (**str != ')') {
            snprintf(error_message, MAX_INPUT, "Missing closing parenthesis");
            return false;
        }
        (*str)++;
        return true;
    }
    else if (isalpha(**str)) {
        char var_name = **str;
        (*str)++;
        for (int i = 0; i < var_count; i++) {
            if (variables[i].name == var_name) {
                *result = variables[i].value;
                return true;
            }
        }
        snprintf(error_message, MAX_INPUT, "Undefined variable '%c'", var_name);
        return false;
    }
    
    snprintf(error_message, MAX_INPUT, "Unexpected character '%c'", **str);
    return false;
}

// 解析项（乘除运算）
bool parse_term(char** str, double* result) {
    if (!parse_factor(str, result)) return false;
    
    while (true) {
        skip_spaces(str);
        char op = **str;
        if (op != '*' && op != '/') break;
        (*str)++;
        
        double rhs;
        if (!parse_factor(str, &rhs)) return false;
        
        if (op == '/') {
            if (rhs == 0) {
                snprintf(error_message, MAX_INPUT, "Division by zero");
                return false;
            }
            *result /= rhs;
        } else {
            *result *= rhs;
        }
    }
    return true;
}

// 解析表达式（加减运算）
bool parse_expression(char** str, double* result) {
    if (!parse_term(str, result)) return false;
    
    while (true) {
        skip_spaces(str);
        char op = **str;
        if (op != '+' && op != '-') break;
        (*str)++;
        
        double rhs;
        if (!parse_term(str, &rhs)) return false;
        
        if (op == '+') {
            *result += rhs;
        } else {
            *result -= rhs;
        }
    }
    return true;
}

// 处理赋值语句
bool handle_assignment(const char* input) {
    char* str = (char*)input;
    skip_spaces(&str);
    
    if (!isalpha(*str)) {
        snprintf(error_message, MAX_INPUT, "Invalid variable name");
        return false;
    }
    
    char var_name = *str;
    str++;
    skip_spaces(&str);
    
    if (*str != '=') {
        snprintf(error_message, MAX_INPUT, "Missing '=' in assignment");
        return false;
    }
    
    str++;
    double value;
    if (!parse_expression(&str, &value)) return false;
    
    // 检查是否有多余字符
    skip_spaces(&str);
    if (*str != '\0' && *str != '\n') {
        snprintf(error_message, MAX_INPUT, "Invalid characters after expression");
        return false;
    }
    
    // 更新或创建变量
    for (int i = 0; i < var_count; i++) {
        if (variables[i].name == var_name) {
            variables[i].value = value;
            return true;
        }
    }
    
    if (var_count >= MAX_VARS) {
        snprintf(error_message, MAX_INPUT, "Variable limit reached");
        return false;
    }
    
    variables[var_count++] = (Variable){var_name, value};
    return true;
}

int main() {
    char input[MAX_INPUT];
    printf("Simple Calculator (type 'exit' to quit)\n");
    
    while (1) {
        printf("> ");
        if (!fgets(input, MAX_INPUT, stdin)) break;
        
        // 移除换行符
        input[strcspn(input, "\n")] = '\0';
        
        // 退出命令
        if (strcmp(input, "exit") == 0) break;
        
        // 清空错误信息
        error_message[0] = '\0';
        
        if (strchr(input, '=') != NULL) {
            if (!handle_assignment(input)) {
                printf("Error: %s\n", error_message);
            }
        } else {
            char* str = input;
            double result;
            if (parse_expression(&str, &result)) {
                // 检查是否解析完整个输入
                skip_spaces(&str);
                if (*str != '\0') {
                    printf("Error: Invalid expression syntax\n");
                } else {
                    printf("= %.2f\n", result);
                }
            } else {
                printf("Error: %s\n", error_message);
            }
        }
    }
    
    return 0;
}