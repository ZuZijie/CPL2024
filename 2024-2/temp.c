#include "stdio.h"
int main ()
{
    long long int ans=1,n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++)
    {
        ans=ans*i;
        ans=ans%1000000007;
        sum+=(ans%1000000007);
        sum=sum%1000000007;
    }
  printf("%d",sum); 
}