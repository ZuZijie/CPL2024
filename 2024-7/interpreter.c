#include "stdio.h"
int main()
{
    int a=0;
    int *x=&a;
    scanf("%x",&a);
    printf("%d\n",x);
    printf("%u\n",x);
    printf("%.6f\n",*x);
    printf("%.4e\n",*x);
    return 0;
}