#include "stdio.h"
int findTwoIn2DArray(int arr[][502], int rows, int cols, int target, int *firstRow, int *firstCol, int *secondRow, int *secondCol) {
    int foundCount = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == target) {
                if (foundCount == 0) {
                    *firstRow = i;
                    *firstCol = j;
                    foundCount++;
                } else if (foundCount == 1) {
                    *secondRow = i;
                    *secondCol = j;
                    foundCount++;
                    return 1;
                }
            }
        }
    }
    return 0; 
}
int main()
{
    int n,m;
    int firstrow,secondrow,firstcol,secondcol;
    scanf("%d %d",&n,&m);
    int arr[502][502]={0};
    int ans[114514]={0};
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int k=1;k<((n*m)/2+1);k++)
    {
        findTwoIn2DArray(arr,n+2,m+2,k,&firstrow,&firstcol,&secondrow,&secondcol);
        int temp=1;
        for(int i=firstrow-1;i>=0;i--)
        {
            if(arr[i][firstcol]!=0)
            {
                temp--;
                break;
            }
        }
         for(int i=secondrow-1;i>=0;i--)
        {
            if(arr[i][secondcol]!=0)
            {
                temp--;
                break;
            }
        }
       if(temp==1){
            ans[k]=1;
            arr[firstrow][firstcol]=0;
            arr[secondrow][secondcol]=0;
        }
        temp=1;
        for(int i=firstrow+1;i<=n+1;i++)
        {
            if(arr[i][firstcol]!=0)
            {
                temp--;
                break;
            }
        }
        for(int i=secondrow+1;i<=n+1;i++)
        {
            if(arr[i][secondcol]!=0)
            {
                temp--;
                break;
            }
        }
        if(temp==1){
            ans[k]=1;
            arr[firstrow][firstcol]=0;
            arr[secondrow][secondcol]=0;
        }
        temp=1;
        //cut
          for(int i=firstcol-1;i>=0;i--)
        {
            if(arr[firstrow][i]!=0)
            {
                temp--;
                break;
            }
        }
         for(int i=secondcol-1;i>=0;i--)
        {
            if(arr[secondrow][i]!=0)
            {
                temp--;
                break;
            }
        }
        if(temp==1){
            ans[k]=1;
            arr[firstrow][firstcol]=0;
            arr[secondrow][secondcol]=0;
        }
        temp=1;
        for(int i=firstcol+1;i<=m+1;i++)
        {
            if(arr[firstrow][i]!=0)
            {
                temp--;
                break;
            }
        }
        for(int i=secondcol+1;i<=m+1;i++)
        {
            if(arr[secondrow][i]!=0)
            {
                temp--;
                break;
            }
        }
        if(temp==1){
            ans[k]=1;
            arr[firstrow][firstcol]=0;
            arr[secondrow][secondcol]=0;
        }
        
        
    }
    for (int k=1;k<=n*m/2;k++)
    {
        if(ans[k])printf("%d ",k);
    }
    return 0;
}