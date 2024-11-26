#include "stdio.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "string.h"
=======
>>>>>>> 100640cb13c80a71c87235ea53ec9b0efc68bfa8
=======
>>>>>>> 100640cb13c80a71c87235ea53ec9b0efc68bfa8
#include "stdlib.h"
int main()
{
    int n;
    scanf("%d",&n);
<<<<<<< HEAD
<<<<<<< HEAD
    char *str,*tempstr;
    str=(char *)malloc(100000*sizeof(char));
    tempstr=(char *)malloc(100000*sizeof(char));
    memset(str,'0',sizeof(char)*100000);
    memset(tempstr,'0',sizeof(char)*100000);
    scanf("%s",(str+3));
    int length=strlen(str);
    for(int z=0;z<n;z++)
    {
        for(int i=3;i<length;i++)
    {
        int numA=0,numB=0,empty=0;
        for(int j=-3;j<4;j++)
        {
            if(*(str+i+j)=='A')numA++;
            if(*(str+i+j)=='B')numB++;
            if(*(str+i+j)=='.')empty++;
            
        }
        if(*(str+i)=='A')numA--;
        if(*(str+i)=='B')numB--;
        if(*(str+i)=='A')
        {
            if(numB!=0)*(tempstr+i)='.';
            else if(numA<2||numA>4)*(tempstr+i)='.';
            else *(tempstr+i)=*(str+i);
        }
        if(*(str+i)=='B')
        {
            if(numA!=0)*(tempstr+i)='.';
            else if(numB<2||numB>4)*(tempstr+i)='.';
            else *(tempstr+i)=*(str+i);
        }
        if(*(str+i)=='.')
        {
            if(numA==0&&numB>1&&numB<5)*(tempstr+i)='B';
            else if(numB==0&&numA>1&&numA<5)*(tempstr+i)='A';
            else *(tempstr+i)=*(str+i);
        }
    }
    for(int i=3;i<length;i++)*(str+i)=*(tempstr+i);
    }
    for(int i=3;i<length;i++)
    {
        printf("%c",*(str+i));
=======
=======
>>>>>>> 100640cb13c80a71c87235ea53ec9b0efc68bfa8
    char *str;
    str=(char *)malloc(1000*sizeof(char));
    scanf("%s",str);
    for(int i=0;i<n;i++)
    {
        
<<<<<<< HEAD
>>>>>>> 100640cb13c80a71c87235ea53ec9b0efc68bfa8
=======
>>>>>>> 100640cb13c80a71c87235ea53ec9b0efc68bfa8
    }
}