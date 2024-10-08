#include "stdio.h"
#include "math.h"
int main()
{
    double p,q;
    double x,m,n;
    scanf("%lf %lf",&p,&q);
    m=-q/2+sqrt(q*q/4+p*p*p/27);
    n=-q/2-sqrt(q*q/4+p*p*p/27);
    if(n>=0)
    {
       if(m>=0)
       x=pow(m,1.0/3)+pow(n,1.0/3);
       else
       x=-pow(-m,1.0/3)+pow(n,1.0/3);
        
    }
    else{
      if(m>=0)
      x=pow(m,1.0/3)-pow(-n,1.0/3);
      else
      x=-pow(-m,1.0/3)-pow(-n,1.0/3);
    }
    printf("%.3f",x);
    return 0;
}