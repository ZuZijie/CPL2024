#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#define size 602
int SearchSurrounding(char array[][size][size], int a, int b, int c) 

{
    if (!isdigit(array[a][b][c])) return 0;

    else{
        int temp = array[a][b][c] - '0';

    if (a + 1 < 602 && array[a+1][b][c] == '*') temp--;
    if (a - 1 >= 0 && array[a-1][b][c] == '*') temp--;
    if (b + 1 < 602 && array[a][b+1][c] == '*') temp--;
    if (b - 1 >= 0 && array[a][b-1][c] == '*') temp--;
    if (c + 1 < 602 && array[a][b][c+1] == '*') temp--;
    if (c - 1 >= 0 && array[a][b][c-1] == '*') temp--;

    if (temp == 0) 
        return atoi(&array[a][b][c]);
    else 
        return -1;
    }
}
int wrongposi[100][3];
char arr[602][602][602];
char tempchar[100000000];
int main()
{
    int n;
    
    scanf("%d",&n);
    
    scanf("%s",tempchar);
    int temp=0;
    int x,y,z;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                arr[i][j][k]=tempchar[temp];
                temp++;
                if(arr[i][j][k]=='?')
                {
                    x=i;y=j;z=k;
                }
            }
        }
    }


    int valid1=1;
    temp=0;
    if(arr[x-1][y][z]=='*')temp++;
    if(arr[x+1][y][z]=='*')temp++;
    if(arr[x][y+1][z]=='*')temp++;
    if(arr[x][y-1][z]=='*')temp++;
    if(arr[x][y][z+1]=='*')temp++;
    if(arr[x][y][z-1]=='*')temp++;
    arr[x][y][z]=temp+'0';
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                if(SearchSurrounding(arr,i,j,k)==-1)
                {
                    valid1=0;
                }
            }
        }
    }
    if(valid1==1)
    {
        printf("valid\n%d",SearchSurrounding(arr,x,y,z));
        return 0;
    }
    else
    {
        arr[x][y][z]='*';
        int valid2=1;
        int tempnumber=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                for(int k=1;k<n+1;k++)
                {
                    if(SearchSurrounding(arr,i,j,k)==-1)
                    {
                        valid2=0;
                        wrongposi[tempnumber][0]=i;
                        wrongposi[tempnumber][1]=j;
                        wrongposi[tempnumber][2]=k;
                        tempnumber++;
                    }
                }
            }
        }
        if(valid2==1)
        {
            printf("valid\n*");
        }
        if(valid2==0)
        {
            printf("invalid\n");
            for(int i=0;i<tempnumber;i++)
            {
                printf("%d %d %d\n",wrongposi[i][0],wrongposi[i][1],wrongposi[i][2]);
            }
        }
        return 0;
    }
}