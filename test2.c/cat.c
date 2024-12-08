#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
int arr[1000000];
int main() {
    long long int N,R,M,D;
    scanf("%lld %lld %lld %lld",&N,&R,&M,&D);
    int L=R/2;
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&arr[i]);
    }
    int temp0=0;int temp1=0;
    for(int i=0;i<N;i++)
    {
        if(arr[i]>0&&arr[i]<R){
            temp0++;
            temp1+=arr[i];
        }
    }
    if(temp0<M ||temp1<D)
    {
        printf("-1");
        return 0;
    }
    int low=0,high=R,middle=high-(high-low)/2;

    while(low<=high)
    {
        int tempnum=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]>middle&&arr[i]<R)tempnum++;
        }
        if(tempnum>=M)
        {
            int sum=0;
            for(int i=0;i<N;i++)
            {
                if(arr[i]>middle&&arr[i]<R)sum+=arr[i]-middle;
            }
            if(sum>=D)
            {
                
                low=middle+1;
                middle=high-(high-low)/2;
                continue;
            }
            else
            {
                high=middle-1;
                middle=high-(high-low)/2;
                continue;
            }
        }
        else
        {
            high=middle-1;
            middle=high-(high-low)/2;
        }
    }
    printf("%d",middle);
    return 0;
}
