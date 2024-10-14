#include "stdio.h"
int main ()
{
    int n,sum=0;
    scanf("%d",&n);
    int arr[2000];
    for(int i=0;i<n;i++)
    {
        arr[i]=0;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(j%i==0)
            {
                if(arr[j-1])arr[j-1]=0;
                else arr[j-1]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i])printf("%d ",i+1);
    }
    return 0;
}