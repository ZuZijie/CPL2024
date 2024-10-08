#include "stdio.h"
int main()
{
    int a,b,c,max;
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b&&a>=c)max=a;
    if(b>=a&&b>=c)max=b;
    if(c>=a&&c>=b)max=c;
    if(a+b+c<=2*max)printf("not triangle");
    else
    {
        if(a==b&&b==c)printf("equilateral ");
        else{
            if(a*a+b*b+c*c==max*max*2)printf("right ");
            if(a*a+b*b+c*c>max*max*2)printf("acute ");
            if(a*a+b*b+c*c<max*max*2)printf("obtuse ");
            if(a==b||a==c||b==c)printf("isosceles ");

        }
        printf("triangle");
    }
    return 0;
}