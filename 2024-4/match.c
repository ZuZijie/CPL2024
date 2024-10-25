#include "stdio.h"
void findAllPairs(int arr[][502], int rows, int cols, int result[][4]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num = arr[i][j];  
            if (result[num][0] == 0 && result[num][1] == 0) {
                result[num][0] = i;
                result[num][1] = j;
            } else {
                result[num][2] = i;
                result[num][3] = j;
            }
        }
    }
}


int main()
{
    int n,m;
    int firstrow,secondrow,firstcol,secondcol;
    scanf("%d %d",&n,&m);
    int arr[502][502]={0};
    int ans[125000]={0};
    int result[125000][4]={0};
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    findAllPairs(arr, n+2, m+2,result);
    for(int k=1;k<((n*m)/2+1);k++)
    {   
        firstrow=result[k][0];
        firstcol=result[k][1];
        secondrow=result[k][2];
        secondcol=result[k][3];
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