#include "stdio.h"
#include "math.h"
#include "limits.h"
#include "stdlib.h"
int raw_arr[1000][1000];
int left_sum(int arr[][1000],int c,int x,int y)
{
    int temp=0;
    for(int i=-c;i<1;i++)
    {
        temp+=arr[x+i][y+i];
    }
    for(int i=-c+1;i<1;i++)
    {
        temp+=arr[x+i][y-i];
    }
    return temp;
}

int right_sum(int arr[][1000],int c,int x,int y)
{
    int temp=0;
    for(int i=-c;i<1;i++)
    {
        temp+=arr[x-i][y+i];
    }
    for(int i=-c+1;i<1;i++)
    {
        temp+=arr[x-i][y-i];
    }
    return temp;
}

int up_sum(int arr[][1000],int c,int x,int y)
{
    int temp=0;
    for(int i=-c;i<1;i++)
    {
        temp+=arr[x+i][y-i];
    }
    for(int i=-c+1;i<1;i++)
    {
        temp+=arr[x-i][y-i];
    }
    return temp;
}

int down_sum(int arr[][1000],int c,int x,int y)
{
    int temp=0;
    for(int i=-c;i<1;i++)
    {
        temp+=arr[x+i][y+i];
    }
    for(int i=-c+1;i<1;i++)
    {
        temp+=arr[x-i][y+i];
    }
    return temp;
}
int ansiPosi[100000][2];
int main()
{
    int n,m,d;
    int ansN=0;
    int max_sum=0;
    
    scanf("%d %d %d",&n,&m,&d);
    for(int i=d;i<d+n;i++)
    {
        for(int j=d;j<d+m;j++)
        {
            scanf("%d",&raw_arr[i][j]);
        }
    }
    int temp1=1;
    for(int i=-d;i<d+1;i++)
    {
        for(int j=-d;j<d+1;j++)
        {
            if((abs(i)+abs(j))<=d)
            {
                max_sum+=raw_arr[d+i][d+j];
            }
        }
    }
    ansN=1;
    ansiPosi[0][0]=d;
    ansiPosi[0][1]=d;
    for(int i=d;i<d+n;d++)
    {
        int temp2=0;
        for(int p=-d;p<d+1;p++)
        {
            for(int q=-d;q<d+1;q++)
            {
                if((abs(p)+abs(q))<=d)
                {
                    temp2+=raw_arr[i+p][d+q];
                }
            }
        }
        if(temp2==max_sum)
                    {
                        ansiPosi[ansN][0]=i;
                        ansiPosi[ansN][1]=d;
                        ansN++;
                    }
                    if(temp2>max_sum)
                    {
                        max_sum=temp2;
                        for(int p=0;p<ansN;p++)
                        {
                            ansiPosi[i][0]=0;
                            ansiPosi[i][1]=0;
                        }
                        ansiPosi[0][0]=i;
                        ansiPosi[0][1]=d;
                        ansN=1;
                    }

        
        
        temp2=0;
        for(int p=-d;p<d+1;p++)
        {
            for(int q=-d;q<d+1;q++)
            {
                if((abs(p)+abs(q))<=d)
                {
                    temp2+=raw_arr[i+p][d+m-1+q];
                }
            }
        }
        if(temp2==max_sum)
                    {
                        ansiPosi[ansN][0]=i;
                        ansiPosi[ansN][1]=d+m-1;
                        ansN++;
                    }
                    if(temp2>max_sum)
                    {
                        max_sum=temp2;
                        for(int p=0;p<ansN;p++)
                        {
                            ansiPosi[i][0]=0;
                            ansiPosi[i][1]=0;
                        }
                        ansiPosi[0][0]=i;
                        ansiPosi[0][1]=d+m-1;
                        ansN=1;
                    }


        if(temp1==1)
        {
            for(int j=d+1;j<d+m;j++)
            {
                if(right_sum(raw_arr,d,i,j)>=left_sum(raw_arr,d,i,j-1))
                {
                    temp2=0;
                    for(int p=-d;p<d+1;p++)
                    {
                        for(int q=-d;q<d+1;q++)
                        {
                            if((abs(p)+abs(q))<=d)temp2+=raw_arr[i+p][j+q];
                        }
                    }
                    if(temp2==max_sum)
                    {
                        ansiPosi[ansN][0]=i;
                        ansiPosi[ansN][1]=j;
                        ansN++;
                    }
                    if(temp2>max_sum)
                    {
                        max_sum=temp2;
                        for(int p=0;p<ansN;p++)
                        {
                            ansiPosi[i][0]=0;
                            ansiPosi[i][1]=0;
                        }
                        ansiPosi[0][0]=i;
                        ansiPosi[0][1]=j;
                        ansN=1;
                    }
                }
            }
        }  
        if(temp1==-1)
        {
            for(int j=d+m-1;j>d;j--)
            {
                if(left_sum(raw_arr,d,i,j)>=right_sum(raw_arr,d,i,j-1))
                {
                    int temp2=0;
                    for(int p=-d;p<d+1;p++)
                    {
                        for(int q=-d;q<d+1;q++)
                        {
                            if((abs(p)+abs(q))<=d)temp2+=raw_arr[i+p][j+q];
                        }
                    }
                    if(temp2==max_sum)
                    {
                        ansiPosi[ansN][0]=i;
                        ansiPosi[ansN][1]=j;
                        ansN++;
                    }
                    if(temp2>max_sum)
                    {
                        max_sum=temp2;
                        for(int p=0;p<ansN;p++)
                        {
                            ansiPosi[i][0]=0;
                            ansiPosi[i][1]=0;
                        }
                        ansiPosi[0][0]=i;
                        ansiPosi[0][1]=j;
                        ansN=1;
                    }
                }
            }
        } 
    }
    printf("%d\n",max_sum);
    for(int i=0;i<ansN;i++)
    {
        printf("%d %d\n",ansiPosi[i][0],ansiPosi[i][1]);
    }
    return 0;
}