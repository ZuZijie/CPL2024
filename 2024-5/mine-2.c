#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"

char arr_raw[602][602][602];
int arr_num[602][602][602]={0};
int is_valid[602][602][602];

int main()
{
    int n;
    int x,y,z;
    int valid=0;
    scanf("%d",&n);
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                char temp;
                scanf(" %c",arr_raw[i][j][k]);
                if(isdigit(temp))
                {
                    arr_num[i][j][k]=atoi(temp);
                }
                if(temp=='?')
                {
                    x=i;y=j;k=z;
                }
            }
        }
    }
    for(int i=x-1;i<x+2;i++)
    {
        for(int j=y-1;j<y+2;j++)
        {
            for(int k=z-1;k<z+2;k++)
            {
                if(arr_raw[i][j][k]!='*')
                {
                    int count=0;
                    if(arr_raw[i][j][k+1]=='*'||arr_raw[i][j][k+1]=='?')count++;
                    if(arr_raw[i][j][k-1]=='*'||arr_raw[i][j][k-1]=='?')count++;
                    if(arr_raw[i][j+1][k]=='*'||arr_raw[i][j+1][k]=='?')count++;
                    if(arr_raw[i][j-1][k]=='*'||arr_raw[i][j-1][k]=='?')count++;
                    if(arr_raw[i+1][j][k]=='*'||arr_raw[i+1][j][k]=='?')count++;
                    if(arr_raw[i-1][j][k]=='*'||arr_raw[i-1][j][k]=='?')count++;
                    if(count==arr_num[i][j][k])
                    {
                        arr_raw[x][y][z]='*';
                        is_valid[i][j][k]
                    }
                    else
                    {
                    if(arr_raw[i][j][k+1]=='*')count++;
                    if(arr_raw[i][j][k-1]=='*')count++;
                    if(arr_raw[i][j+1][k]=='*')count++;
                    if(arr_raw[i][j-1][k]=='*')count++;
                    if(arr_raw[i+1][j][k]=='*')count++;
                    if(arr_raw[i-1][j][k]=='*')count++;
                    if(count==arr_num[i][j][k])
                    {
                        valid=1;
                        arr_num[x][y][z]=count;
                    }
                    }
                }
            }
        }
    }
}