#include "stdio.h"
int main ()
{
    int n;
    int temp;
    int ans1=-1,ans2=0,ans3=0;
    scanf("%d",&n);
    int input[18]={0};
    int a;
    int arr[18]={0,0,3,0,0,0,0,0,0,0,0,0,0,14,15,16,0,18};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        ans1=ans1&arr[temp-1];
        ans2=ans2|arr[temp-1];
        ans3=ans3^arr[temp-1];
    }
    printf("%d %d %d",ans1,ans2,ans3);
    return 0;
}   