#include "stdio.h"
#include <stdlib.h>
#include <string.h>
void paixv(int arr[],int l)
{
    int temp=0;
    for(int i=0;i<l;i++)
    {
        for (int j=0;j<l-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;       
            }
        }
    }
}
int main()
{
    int temp;
    int arr[10000]={0};
    while(1)
        scanf("%d",&temp);
        if(temp==-1)break;
        else arr[i]=temp;
    }
    arr=realloc(arr,(size+1))
}
