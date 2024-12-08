#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "stdbool.h"
char arr[400][10000];
char str1[1000000], str2[1000000];
                
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    char input[100000];
    scanf("%s",input);
    for(int i=0;i<n;i++)
    {
        
        if(arr[i][0]=='.')
        {
            int temp,num=0;
            for(int j=2;j<strlen(arr[i]);j++)
            {
                if(arr[i][j]==']')
                {
                    temp=j;
                    num=1;
                    break;
                }
                else{
                    str1[j-2]=arr[i][j];
                }
            }
            for(int j=temp+3;j<strlen(arr[i])-1;j++)
            {
                str2[j-temp-3]=arr[i][j];
            }
            if(arr[i][temp+1]=='.')
            {
                char tempstr[10000],temp2str[10000];
                char *tempposi=strstr(input,str1);
                if(tempposi!=NULL)
                {
                int str1len=strlen(str1);

                for(int j=0;j<(tempposi-input);j++)
                {
                    tempstr[j]=input[j];
                }
                for(int j=(tempposi-input)+str1len;j<strlen(input);j++)
                {
                    temp2str[j-(tempposi-input)-str1len]=input[j];
                }
                //printf("%s\n%s\n%s\n",tempstr,str2,temp2str);
                strcat(tempstr,str2);
                strcat(tempstr,temp2str);
                strcpy(input,tempstr);
                strcpy(tempstr,"\0");
                strcpy(temp2str,"\0");
                }
            }
        }
        
    }
    printf("%s",input);
    return 0;
}