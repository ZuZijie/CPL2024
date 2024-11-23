#include "stdio.h"
#include "math.h"
#include "limits.h"
#include "stdlib.h"
int raw_arr[1000][1000];
int CalSurrounding(int array[][1000],int c,int x,int y)
{
    int temp=0;
    for(int i=-c;i<c+1;i++)
    {
        for(int j=-c;j<c+1;j++)
        {
            if((abs(i)+abs(j))<=c)temp+=array[x+i][y+j];
        }
    }
    return temp;
}
int left_sum(int array[][1000],int c,int x,int y)
{
    int temp=0;
    for(int i=0;i<c+1;i++)
    {
        temp+=array[x+i][y+i-c];
    }
    for(int i=1;i<1+c;i++)
    {
        temp+=array[x-i][y+i-c];
    }
    return temp;
}

int right_sum(int array[][1000],int c,int x,int y)
{
    int temp=0;
    for(int i=0;i<c+1;i++)
    {
        temp+=array[x+i][y-i+c];
    }
    for(int i=1;i<c+1;i++)
    {
        temp+=array[x-i][y-i+c];
    }
    return temp;
}

void RegengerateAns(int arr[][2],int *length,int x,int y)
{
    for(int i=0;i<*length;i++)
    {
        arr[i][0]=0;arr[i][1]=0;
    }
    *length=1;
    arr[0][0]=x;arr[0][1]=y;
}
int ansiPosi[100000][2];

void AddAns(int arr[][2],int *length,int x,int y)
{
    arr[*length][0]=x;
    arr[*length][1]=y;
    *length++;
}

int main()
{
    int n,m,d;
    int ansN=1;
    int max_sum=INT_MIN;
    scanf("%d %d %d",&n,&m,&d);
    for(int i=d;i<d+n;i++)
    {
        for(int j=d;j<d+m;j++)
        {
            scanf("%d",&raw_arr[i][j]);
        }
    }
    for(int i=d;i<d+n;i++)
    {
            int tempvalue=CalSurrounding(raw_arr,d,i,d);
            if(tempvalue>max_sum)
            {
                RegengerateAns(ansiPosi,&ansN,i,d);
                max_sum=tempvalue;
            }
            if(tempvalue==max_sum)AddAns(ansiPosi,&ansN,i,d);
            for(int j=d+1;j<d+m-1;j++)
            {
                tempvalue=tempvalue-left_sum(raw_arr,d,i,j-1)+right_sum(raw_arr,d,i,j);
                if(tempvalue>max_sum)
                {
                    RegengerateAns(ansiPosi,&ansN,i,j);
                    max_sum=tempvalue;
                }
                if(tempvalue==max_sum)AddAns(ansiPosi,&ansN,i,j);
            }
    }
    printf("%d %d\n",max_sum,ansN);
    for(int i=0;i<ansN;i++)
    {
        printf("%d %d\n",ansiPosi[i][0]-d+1,ansiPosi[i][1]-d+1);
    }
    return 0;
}