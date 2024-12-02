#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"
int IsReserved(char input)
{
    char *reservedWords[]={ "const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break","enum", "struct", "typedef", "union", "goto"};
    for(int i=0;i<16;i++)
    {
        if(input==reservedWords[i])
        {
            return 1;
        }
    }
    return 0;
}
int IsOperator(char input)
{
    char *operator[]={'+','-','*','/','=','==','!=',">=","<=",'>','<'};
    for(int i=0;i<11;i++)
    {
        if(input==operator[i])return 1;
    }
    return 0;
}
int IsIntegerorFloat(char *input)
{
    int numofDot = 0;
    if (*input == '.') 
    {
        for (int i = 0; i < strlen(input); i++) 
        {
            input[i] = input[i + 1];
        }
        numofDot++;
    }

    
    if (IsOperator(*input)) {
        return -1;  
    }

    if (!isdigit(*input)) {
        return 0;  
    }

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
    if(numofDot>0)return 2;//浮点输出2
    return 1;//整数输出1
}
    