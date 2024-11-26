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
            int temp=0;
            for(int i=0;i<length2;i++)
            {
                char *tempstr;
                tempstr=(char *)malloc(1000*sizeof(char));
                for(int j=0;j<=i;j++)
                {
                    *(tempstr+j)=*(str1+length1-i+j);
                    
                }
                char *posi=strstr(str2,tempstr);
                if(tempstr==str2)temp++;
                else break;
            }
            char *tempstr;
            tempstr=(char *)malloc(1000*sizeof(char));
            for(int i=temp;i<length2;i++)
            {
                *(tempstr+i-temp)=*(str2+i);
            }
            mystrcat(str1,tempstr);
            printf("%s\n",str1);
        }
    }