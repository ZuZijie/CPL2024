#include "stdio.h"
#include "ctype.h"
#include "math.h"
int main()
{
    int n,length=0,ans[10000]={0};
    char input[16];
    char ch;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        length=0;
        for(int j=0;j<15;j++)
        {
            scanf("%s",&ch);
            if(ch=='\n')break;
            input[i]=ch;
            length++;
        }
        for(int j=0;j<length;j++)if(input[j]!='0'&&input[j]!='Z'&&input[j]!='1')ans[i]=1919810;
        for(int j=0;j<length;j++)
        {
            if(input[j]=='0') ans[i]=ans[i];
            if(input[j]=='1') ans[i]+=pow(3,length-1-i);
            if(input[j]=='Z') ans[i]-=pow(3,length-1-i);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ans[i]==1919810)printf("Radix Error\n");
        else printf("%d\n",ans[i]);
    }
    return 0;
    
}