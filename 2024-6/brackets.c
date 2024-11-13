#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "assert.h"
#include "string.h"

typedef int STDataType;  // 修改为int类型
typedef struct stack
{
    STDataType* a;
    int top;
    int capacity;
} ST;

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
    ps->a[ps->top] = x;
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
        printf("| %d |\n", ps->a[i]);  // 输出整数
    }
    printf("|===|\n");
}

int main()
{
    ST stack;
    STInit(&stack);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char arr[100000];
        scanf("%s", arr);
        int is_legal = 1;

        for (int j = 0; arr[j] != 0; j++)
        {
            if (arr[j] == '{') STPush(&stack, 1);
            if (arr[j] == '[') STPush(&stack, 2);
            if (arr[j] == '(') STPush(&stack, 3);
            if (arr[j] == '}')
            {
                if (STEmpty(&stack) || STTop(&stack) != 1)
                {
                    is_legal = 0;
                    break;
                }
                STPop(&stack);
            }
            if (arr[j] == ']')
            {
                if (STEmpty(&stack) || STTop(&stack) != 2)
                {
                    is_legal = 0;
                    break;
                }
                STPop(&stack);
            }
            if (arr[j] == ')')
            {
                if (STEmpty(&stack) || STTop(&stack) != 3)
                {
                    is_legal = 0;
                    break;
                }
                STPop(&stack);
            }
        }

        if (is_legal && STEmpty(&stack))
            printf("True\n");
        else
            printf("False\n");
    return 0;
}
}
