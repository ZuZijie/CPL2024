    #include "stdio.h"
    #include "string.h"
    #include "stdlib.h"
   void mystrcat(char *str1,char *str2)
    {
        int length1=strlen(str1);
        int length2=strlen(str2);
        for(int i=length1;i<length1+length2;i++)
        {
            *(str1+i)=*(str2+i-length1);
        }
    }
    int findsamelength(char *str1, char *str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    int samelength = 0;
    for (int i = length1 - 1; i >= 0; i--) {
        int j = 0;
        char *tempstr;
        tempstr=(char *)malloc(1000*sizeof(char));
        for(int j=0;j<i;j++)
        {
            *(tempstr+j)=*(str1+length1-i+j-1);
        }
        if(strstr(str2,tempstr)==str2)
        {
            samelength=i+1;
            break;
        }
    }
    return samelength;
    }
    int main()
    {
        int n;
        scanf("%d",&n);
        for(int t=0;t<n;t++)
        {
            char *str1;
            char *str2;
            str1=(char *)malloc(sizeof(char)*2000);
            str2=(char *)malloc(sizeof(char)*1000);
            scanf("%s %s",str1,str2);
            int length1=strlen(str1);
            int length2=strlen(str2);
            int samelength=length1;          
            char *tempstr;
            samelength=findsamelength(str1,str2);
            tempstr=(char *)malloc(1000*sizeof(char));
            for(int i=samelength;i<length2;i++)
            {
                *(tempstr+i-samelength)=*(str2+i);
            }
            mystrcat(str1,tempstr);
            printf("%s\n",str1);
        }
    }