#include <stdio.h>
#include <math.h>
int converter(int n, int m)
{
    return n*(m/10)+m%10;
}
int main()
{
    int p,q,r,result=0;
    scanf("%d %d %d",&p,&q,&r);
    for(int i=2;i<41;i++)
    {
        if(i>(p/10)&&i>(p%10)&&i>(q/10)&&i>(q%10)&&i>(r/10)&&i>(r%10))
        {
            if(converter(i,p)*converter(i,q)==converter(i,r))
        {
            result=i;
            break;
        }
        }
    }
    printf("%d",result);
    return 0;
}
