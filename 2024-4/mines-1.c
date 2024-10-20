#include "stdio.h"
int main()
{
    int n;
    char arr[102][102];
    int count[102][102]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int near[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
            for (int k = 0; k < 8; ++k)
            {
                int newI = i + near[k][0];
                int newJ = j + near[k][1];
                if (arr[newI][newJ] == '*') 
                {
                    count[i][j]++;
                }
            }
 
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i][j]=='o')printf("%d",count[i][j]);
            else if(arr[i][j]=='*')printf("*");
            
        }
        printf("\n");
    }
    return 0;
}