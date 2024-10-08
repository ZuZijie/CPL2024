#include "stdio.h"
#include "math.h" 
int main ()
{
    int a,year,day,month,JDN,y;
    scanf("%d %d %d",&year,&month,&day);
    a=floor((14-month)/12);
    y=year+4800-a;
    int m=month+12*a-3;
    JDN=day+floor((153*m+2)/5)+365*y+floor(y/4)-y/100+y/400-32045;
    printf("%d",JDN);
    return 0;
}