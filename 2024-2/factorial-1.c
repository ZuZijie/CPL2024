#include "stdio.h"
int main()
{
    int n=0,s=1,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        s=s*i;
        s=s%10007;
        sum+=s;
    }
    printf("%d",sum%10007);
    return 0;
}