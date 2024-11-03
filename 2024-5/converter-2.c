#include "stdio.h"
void converter(int num) {
    int h = num / 100;
    int t = (num % 100) / 10;
    int o = num % 10;

    if (num == 0) {
        printf("zero");

    }

    if (h) {
        switch (h) {
            case 1: printf("one hundred "); break;
            case 2: printf("two hundred "); break;
            case 3: printf("three hundred "); break;
            case 4: printf("four hundred "); break;
            case 5: printf("five hundred "); break;
            case 6: printf("six hundred "); break;
            case 7: printf("seven hundred "); break;
            case 8: printf("eight hundred "); break;
            case 9: printf("nine hundred "); break;
        }
        if(t+o!=0)printf("and ");
    }

    if (t == 1) {
        switch (o) {
            case 0: printf("ten"); break;
            case 1: printf("eleven"); break;
            case 2: printf("twelve"); break;
            case 3: printf("thirteen"); break;
            case 4: printf("fourteen"); break;
            case 5: printf("fifteen"); break;
            case 6: printf("sixteen"); break;
            case 7: printf("seventeen"); break;
            case 8: printf("eighteen"); break;
            case 9: printf("nineteen"); break;
        }
    } else {
        if (t) {
            switch (t) {
                case 2: printf("twenty"); break;
                case 3: printf("thirty"); break;
                case 4: printf("forty"); break;
                case 5: printf("fifty"); break;
                case 6: printf("sixty"); break;
                case 7: printf("seventy"); break;
                case 8: printf("eighty"); break;
                case 9: printf("ninety"); break;
            }
            if (o) printf("-");
        }
        if (o) {
            switch (o) {
                case 1: printf("one"); break;
                case 2: printf("two"); break;
                case 3: printf("three"); break;
                case 4: printf("four"); break;
                case 5: printf("five"); break;
                case 6: printf("six"); break;
                case 7: printf("seven"); break;
                case 8: printf("eight"); break;
                case 9: printf("nine"); break;
            }
        }
    }

}
int main ()
{
    double temp;
    int n;
    scanf("%f",&temp);
    if(temp<-2147483647.0)printf("minus two billion one hundred and forty-seven million four hundred and eighty-three thousand six hundred and forty-eight");
    else 
    {
        n=(int)temp;
    if(n<0)
    {
        printf("minus ");
        n=-n;
    }
    if(n/1000000000!=0)
    {
        converter(n/1000000000);
        printf(" billion ");
    }
    if(n/1000000!=0&&(n/1000000)%1000!=0)
    {
        converter((n%1000000000)/1000000);
        printf(" million ");
    }
    if(n/1000!=0&&(n/1000)%1000!=0)
    {
        converter((n%1000000)/1000);
        printf(" thousand ");
    }
    if(n%100!=0)
    {
        converter(n%1000);
    }
    return 0;
    }
}