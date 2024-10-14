#include "stdio.h"
int main()
{
    int m,n,d=0;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m+n-1;i++)
    {
        if(n!=7)n+=1;
        else n=0;
        if(i<n+1)printf("   ");
        else 
        {
            d++;
            printf("%2d ",d);
        }
        if(i%7==0)printf("\n");

    }
}