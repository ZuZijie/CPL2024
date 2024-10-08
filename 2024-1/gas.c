#include "stdio.h"
#define R 8.314
int main()
{
    float P,L,T,n;
    scanf("%f %f %f",&P,&L,&T);
    n=(P*L*L*L)/(R*T);
    printf("%.4e",n);
    return 0;
}