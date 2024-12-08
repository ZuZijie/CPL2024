#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int compar(const void *a,const void *b)
{
    return (*(int *)a-*(int *)b);
}
int main()
{
    int arr[100000];
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<q;i++)
    {
        int temp;
        scanf("%d",&temp);
        int *result=bsearch(&temp,arr,n,sizeof(int),compar);
        if(result==NULL)
        {
            printf("-1");
        }
        else{
            printf("%d\n",result-arr);
        }
    }
    return 0;
}