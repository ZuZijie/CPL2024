#include "stdio.h"
#define N 11451
int main()
{
    int n,s=0,sum=0;
    int arr[N];
    scanf("%d",&n);
    for(int i=0;i<n+1;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n+1;i++)
    {
        if(sum<i)
        {
            s+=i-sum;
            sum=i;
        }
        sum+=arr[i];
    }
    printf("%d",s);
    return 0;
}