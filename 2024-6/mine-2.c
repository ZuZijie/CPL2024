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
        return 1;
    else 
        return -1;
    }
}

    char arr[size][size][size];
    char tempchar[size*size*size];
int main()
{

    int n;
    int wrongposi[35][3];
    int x,y,z;
    int temp=0;
    int valid=0;
    int specialvalid=0;
    int valid2=1;
    scanf("%d",&n);
    /*for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                scanf(" %c",&arr[i][j][k]);
                if(arr[i][j][k]=='?')
                {
                    x=i;y=j;z=k;     
                }
            }
        }
    }*/
    
    scanf("%s",tempchar);
    int p=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {

                arr[i][j][k]=tempchar[p];
                p++;
                if(arr[i][j][k]=='?')
                {
                    x=i;y=j;z=k;     
                }
            }
        }
    }

    arr[x][y][z]='*';
    if(SearchSurrounding(arr,x+1,y,z)!=-1&&SearchSurrounding(arr,x-1,y,z)!=-1&&SearchSurrounding(arr,x,y+1,z)!=-1&&SearchSurrounding(arr,x,y-1,z)!=-1&&SearchSurrounding(arr,x,y,z+1)!=-1&&SearchSurrounding(arr,x,y,z-1)!=-1)
    {
        valid=1;
        arr[x][y][z]='0';
        if(SearchSurrounding(arr,x+1,y,z)!=-1&&SearchSurrounding(arr,x-1,y,z)!=-1&&SearchSurrounding(arr,x,y+1,z)!=-1&&SearchSurrounding(arr,x,y-1,z)!=-1&&SearchSurrounding(arr,x,y,z+1)!=-1&&SearchSurrounding(arr,x,y,z-1)!=-1)
        {
            specialvalid=1;
        }
    }
    else
    {
        arr[x][y][z]='0';
        if(SearchSurrounding(arr,x+1,y,z)!=-1&&SearchSurrounding(arr,x-1,y,z)!=-1&&SearchSurrounding(arr,x,y+1,z)!=-1&&SearchSurrounding(arr,x,y-1,z)!=-1&&SearchSurrounding(arr,x,y,z+1)!=-1&&SearchSurrounding(arr,x,y,z-1)!=-1)
        {
            valid=2;
        }
    }
    if(valid==1)
    {
        for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                if(SearchSurrounding(arr,i,j,k)==-1)
                {
                    wrongposi[temp][0]=i;
                    wrongposi[temp][1]=j;
                    wrongposi[temp][2]=k;
                    temp++;
                    valid2=0;
                }
            }
        }
    }
    }
    if(valid==2||specialvalid==1)
    {
        int temp2=0;
        if(arr[x+1][y][z]=='*')temp2++;
        if(arr[x-1][y][z]=='*')temp2++;
        if(arr[x][y+1][z]=='*')temp2++;
        if(arr[x][y-1][z]=='*')temp2++;
        if(arr[x][y][z+1]=='*')temp2++;
        if(arr[x][y][z-1]=='*')temp2++;
        arr[x][y][z]=temp2+'0';
        for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                if(SearchSurrounding(arr,i,j,k)==-1)
                {
                    wrongposi[temp][0]=i;
                    wrongposi[temp][1]=j;
                    wrongposi[temp][2]=k;
                    temp++;
                    valid2=0;
                }
            }
        }
    }   
    }
    if(valid==0)
    {
        arr[x][y][z]='*';
        for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=1;k<n+1;k++)
            {
                if(SearchSurrounding(arr,i,j,k)==-1)
                {
                    wrongposi[temp][0]=i;
                    wrongposi[temp][1]=j;
                    wrongposi[temp][2]=k;
                    temp++;
                    valid2=0;
                }
            }
        }
    }
    }
    if(specialvalid==1&&valid2==1)printf("valid\n%c",arr[x][y][z]);
    else{
        if(valid==1&&valid2==1)printf("valid %c",arr[x][y][z]);
    if(valid==2&&valid2==1)printf("valid %c",arr[x][y][z]);
    if(valid==1&&valid2==0)
    {
        printf("invalid\n");
        for(int i=0;i<temp+1;i++)
        {
            printf("%d %d %d\n",wrongposi[i][0],wrongposi[i][1],wrongposi[i][2]);
        }
    }
    if(valid==2&&valid2==0)
    {
        printf("invalid\n");
        for(int i=0;i<temp;i++)
        {
            printf("%d %d %d\n",wrongposi[i][0],wrongposi[i][1],wrongposi[i][2]);
        }
    }
    if(valid==0)
    {
        printf("invalid\n");
        for(int i=0;i<temp;i++)
        {
            printf("%d %d %d\n",wrongposi[i][0],wrongposi[i][1],wrongposi[i][2]);
        }
    }
    }
    return 0;
}