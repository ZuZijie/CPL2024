#include "stdio.h"
int main()
{
    char name[20];
    char unit;
    double num,frac,factor;
    int pre;
    scanf("%s %d %lf %lf %c",&name,&pre,&frac,&factor,&unit);
    num=frac+pre;
    printf("%.2s: %d (%.5lf) | %.5E %.5lf %c",name,pre,frac,num,num*factor,unit-32);
    return 0;
}