#include "stdio.h"
#include "math.h"
void SplitArray(int a[][2],int n)
{
    for(int i=9998;i>=n;i--)
    {
        a[i+1][0]=a[i][0];
        a[i+1][1]=a[i][1];
    }
    a[n+1][0]--;
    a[n][0]=a[n+1][0];
    a[n][1]=0;
}
int converter(int n)
{
    int i = 0;
    while ((1 << i) < n) // 使用移位运算计算 2^i
    {
        i++;
    }
    return i;
}
int arr[10000][2];
int main()
{
    int n,q;
    int count=0;
    int size=1;
    scanf("%d %d",&n,&q);
    arr[0][0]=q;
    for(int i=0;i<10000;i++)
    {
        arr[i][1]=0;
    }
    for(int i=0;i<q;i++)
    {
        char input;
        scanf(" %c",&input);
        if(input=='A')
        {
            int id,m;
            scanf(" %d %d",&id,&m);
            int mem=converter(m);
            int temp=0;
            int tempMem,tempPosition;
            for(int j=0;j<size;j++)
            {
                if(arr[j][0]==mem&&arr[j][1]==0)
                {
                    temp=1;
                    arr[j][1]=id;
                    break;
                }
            }
            tempMem=mem;
            while (temp==0)
            {
               tempMem++;
               for(int j=0;j<size;j++)
               {
                    if(arr[j][0]==tempMem&&arr[j][1]==0)
                {
                    temp=1;
                    tempPosition=j;
                    break;
                }
                for(int j=0;j<tempMem-mem;j++)
                {
                    SplitArray(arr,tempPosition);
                    size++;
                }
                arr[tempPosition][1]=id;
               } 
            }
            
        }
        if(input=='Q')
        {
            printf("%d\n",size);
            for(int j=0;j<size;j++)
            {
                printf("%d ",arr[j][1]);
            }
        }
    }
    return 0;
}