#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "assert.h"
#include "string.h"

typedef char* STDataType;
typedef struct stack
{
    STDataType* a;
    int top;
    int capacity;
} ST;

#define MAX_INPUT_LENGTH 10000
#define MAX_STRINGS 10000

char global_strings[MAX_STRINGS][MAX_INPUT_LENGTH];  // 全局数组存储字符串
int string_count = 0;  // 当前使用的字符串数量

void STInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = 0;
}

void STPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* temp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
        if (temp == NULL)
        {
            perror("realloc fail!");
            exit(-1);
        }
        ps->a = temp;
        ps->capacity = newcapacity;
    }
    ps->a[ps->top] = x;  // 直接存储字符串指针
    ps->top++;
}

void STPop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

int STSize(ST* ps)
{
    assert(ps);
    return ps->top;
}

STDataType STTop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];
}

bool STEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}

void STDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}

void STPrint(ST* ps)
{
    assert(ps);
    if (STEmpty(ps))
    {
        printf("Empty\n");
        return;
    }
    for (int i = ps->top - 1; i >= 0; i--)
    {
        printf("| %s |\n", ps->a[i]);
    }
    printf("|===|\n");
}

int main()
{
    char input[1000];  // 用于存储命令
    ST stack;
    STInit(&stack);

    int n;
    scanf("%d", &n);  // 读取命令的次数

    // 读取每一条命令
    getchar();  // 清除换行符，避免干扰后续读取

    for (int i = 0; i < n; i++)
    {
        fgets(input, sizeof(input), stdin);  // 使用 fgets 读取命令
        input[strcspn(input, "\n")] = 0;  // 去掉换行符

        if (strncmp(input, "push", 4) == 0)
        {
            char* token = strtok(input, " ");
            if (token && strcmp(token, "push") == 0)
            {
                token = strtok(NULL, " ");
                if (token)
                {
                    // 将字符串存储在全局数组中
                    strcpy(global_strings[string_count], token);
                    STPush(&stack, global_strings[string_count]);
                    string_count++;
                }
                else
                {
                    printf("Invalid input for push command.\n");
                }
            }
        }
        else if (strcmp(input, "pop") == 0)
        {
            if (STSize(&stack) != 0)
            {
                STPop(&stack);
            }
            else
            {
                printf("Empty\n");
            }
        }
        else if (strcmp(input, "top") == 0)
        {
            if (STSize(&stack) != 0)
            {
                printf("%s\n", STTop(&stack));  // 打印栈顶元素
            }
            else
            {
                printf("Empty\n");
            }
        }
        else if (strcmp(input, "print") == 0)
        {
            STPrint(&stack);  // 打印栈
        }
    }

    STDestory(&stack);  // 释放栈资源
    return 0;
}