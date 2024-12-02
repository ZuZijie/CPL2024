#include "stdio.h"
#include "ctype.h"
#include "string.h"
int IsOperator(char input)
{
    const char *operator[] = {"+", "-", "*", "/", "=", "==", "!=", ">=", "<=", ">", "<"};
    for(int i=0;i<11;i++)
    {
        if(input==*operator[i])return 1;
    }
    return 0;
}
int IsIntegerorFloat(char *input)
{
    int numofDot = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '.') {
            numofDot++;
        }
        if (numofDot > 1) {
            return -1;  
        }
        if (!isdigit(input[i]) && input[i] != '.') {
            return -1;  
        }
    }
    if(numofDot>0)return 2;
    return 1;  
}
int main()
{
    char *a="1.05";
    printf("%d",IsIntegerorFloat(a));
}