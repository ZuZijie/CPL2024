#include "stdio.h"
int main()
{
    char first;
    scanf("%c",&first);
    printf("%c",first);
    for(int i=0;i<1023;i++)
    {
        char temp;
        scanf("%c",&temp);
        if (temp==EOF)break;
        if(temp>='A'&&temp<='Z')
        {
            printf(" %c",temp+32);
        }
        else
        {
            printf("%c",temp);
        }
    }
    return 0;
}