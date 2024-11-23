#include "stdio.h"
int main()
{
    int a=0;
    int *x=&a;
    scanf("%x",&a);
    printf("%d\n",*(int *)x);
    printf("%u\n",*(unsigned int *)x);
    printf("%.6f\n",*(float *)x);
    printf("%.4e\n",*(float *)x);
    return 0;
}