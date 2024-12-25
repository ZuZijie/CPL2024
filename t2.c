#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{
    char str[1000]="sjda\0sdadsad";
    printf("%d",sizeof(str));
    printf("%s\n",str);
    for(int i=0;i<10;i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}