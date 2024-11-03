#include "stdio.h"
#include "math.h"
int sum(int a,int b)
{
    int  sum=0;
    for(int i=1;i<a+1;i++)
    {
        for(int j=0;j<i;j++)
        {
            sum+=(int)pow(10,j)*b;
        }
    }
    return sum;
}
int main()
{
    int n,j;
    scanf("%d %d",&n,&j);
    printf("%d",sum(n,j));
    return 0;
}

