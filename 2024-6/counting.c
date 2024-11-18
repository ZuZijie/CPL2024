#include "stdio.h"
int main()
{
    int R,C;
    scanf("%d %d",&R,&C);
    char arr[2000][2000];
    int sum=0;
    for(int i=1;i<R+1;i++)
    {
        for(int j=1;j<C+1;j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }
    for(int i=1;i<R+1;i++)
    {
        for(int j=1;j<C;j++)
        {
            if(arr[i][j]=='/'&&arr[i][j+1]=='\\')
            {
                int count=0;
                while(arr[i+count][j-count]=='/'&&arr[i+count][j+1+count]=='\\')
                {
                    int temp=1;
                    for(int k=0;k<=count;k++)
                    {
                        if(arr[i+count+k+1][j-count+k]!='\\'||arr[i+count+k+1][1+j+count-k]!='/')
                        {
                            temp=0;
                            break;
                        }
                    }
                    if(temp==1)sum+=1;
                    count++;
                }
            }
        }
    }
    printf("%d",sum);
    return 0;
}