#include "stdio.h"
int main()
{
    int t,x;
    
    scanf("%d %d",&t,&x);
    for(int q=0;q<t;q++)
    {
        int result[5]={0};
        
        int temp;
        int n=0;
        scanf("%d",&n);
        int arr[20][20]={0};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)scanf("%d",&arr[i][j]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int temp1=1,temp2=1,temp3=1,temp4=1;
                if(arr[i][j])
                {
                for(int k=1;k<=x-1;k++)
                {
                    if(arr[i][j]!=arr[i][j+k])
                    {
                        temp1=0;
                        break;
                    }
                }
                for(int k=1;k<=x-1;k++)
                {   
                    if(arr[i][j]!=arr[i+k][j])
                    {
                        temp2=0;
                        break;
                    }
                    
                }
                for(int k=1;k<=x-1;k++)
                {
                    if(arr[i][j]!=arr[i+k][k+j])
                    {
                        temp3=0;
                        break;
                    }
                }
                for(int k=1;k<=x-1;k++)
                {
                    if(arr[i][j]!=arr[i+k][j-k])
                    {
                        temp4=0;
                        break;
                    }
                }
                temp=temp1+temp2+temp3+temp4;
                if(temp!=0)result[arr[i][j]]=1;
                }
            }
        }
        if((result[1]+result[4]+result[2])!=1)printf("draw\n");
         else
        {
            for(int i=0;i<5;i++)
            {
            if(result[i]==1)printf("%d\n",i);
            }
        }
    } 
    return 0;
}