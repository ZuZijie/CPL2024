#include "stdio.h"
#include  "ctype.h"
char arr[1000];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%c",&arr[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(isdigit(arr[i]))printf("%c",arr[i]);
        else
        {
           if(arr[i]>='A'&&arr[i]<='Z')printf("%c",arr[i]+32);
           else printf("%c",arr[i]-32); 
        }
    }
    return 0;
}