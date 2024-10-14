#include "stdio.h"
int main()
{
    int t,max=0,n=0;
    scanf("%d",&t);
    int arr[10000],ans[10000];
    for(int i=0;i<n;i++)ans[i]=0;
    for(int j=0;j<t;j++)
    {
          scanf("%d",&n);
          for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++)if(arr[i]>max)max=arr[i];
    if(arr[n-1]>=max)ans[j]=1;
    else ans[j]=0;
    max=0;
    }
    for(int i=0;i<t;i++)
    {
        if(ans[i])printf("Yes\n");
        else printf("No\n");
    }
    
    return 0;
}