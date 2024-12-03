#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int IsValidOption(char a, char rule[], int lengthOfRule) 
{
    for (int i = 0; i < lengthOfRule; i++) 
    {
        if (a == rule[i])
        {
            return 1;
        }
    }
    return 0;
}

int IsOptionRequireValue(char a, char rule[], int lengthOfRule) 
{
   for (int i = 0; i < lengthOfRule; i++) 
   {
        if (a == rule[i]) 
        {
            return (i + 1 < lengthOfRule && rule[i + 1] == ':');
        }
    }
    return 0;
}

char rule[102400], token[102500][1025],valueofRule1[10240][10240];
int main() {
    char name[1025];
    char *optionValues[10000] = {0}; 
    int tokenLength = 0;
    scanf("%s", rule);
    scanf("%s", name);
    int ruleneedvalue[102400]={0};
    char valueofRule[10240][2];
    while (scanf("%s", token[tokenLength]) != EOF) {}

    if (tokenLength == 0) 
    {
        printf("%s\n", name);
        return 0;
    }

    if (tokenLength > 0 && token[tokenLength - 1][0] == '-') 
    {
        int ruleLength = strlen(rule);
        for (int i = 0; i < ruleLength; i++) 
        {
            if (rule[i] == token[tokenLength - 1][1] && IsOptionRequireValue(rule[i], rule, ruleLength))
            {
                printf("%s:option requires an argument -- '%c'\n", name, token[tokenLength - 1][1]);
                return -1;
            }
        }
    }
    int ruleLength = strlen(rule);
    for (int i = 0; i < tokenLength; i++) 
    {
        if (token[i][0] == '-') {
            if (!IsValidOption(token[i][1], rule, ruleLength)) 
            {
                printf("%s:invalid option -- '%c'\n", name, token[i][1]);
                return -2;
            }   
        }
    }
    for(int i=0;i<ruleLength;i++)
    {
        if(rule[i]==':')
        {
            ruleneedvalue[i-1]=1;
        }
    }
    printf("%s\n", name);
    int temp=0;
    for(int i=0;i<tokenLength;i++)
    {
        if(i<tokenLength-1)
        {
            for(int j=0;j<ruleLength;j++)
            {
                if(rule[j]==token[i][1])
                {
                    if(ruleneedvalue[j]==1)
                    valueofRule[temp][0]=rule[j];
                    strcpy(valueofRule1[temp],token[i+1]);
                    temp++;
                }
            }
        }
    }
    for(int i=0;i<tokenLength;i++)
    {
        if(token[i][0]=='-')
        {
            int temp1=0;
            for(int j=temp-1;j>=0;j--)
            {
                if(valueofRule[j][0]==token[i][1])
                {
                    printf("%s=%s\n",token[i][1],valueofRule1[j]);
                    temp1=1;
                    break;
                }
            }
            if(!temp1)printf("%s\n",token[i][1]);
        }
    }
    return 0;
}
