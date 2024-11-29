#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int IsValidOption(char a,char rule[],int lengthOfRule)//寻找输入的参数是否合法
{
    int DidFound=0;
    for(int i=0;i<lengthOfRule;i++)
    {
        if(a==rule[i])
        {
            DidFound=1;
            break;
        }
    }
    return DidFound;
}
int IsOptionRequireValue(char a,char rule[],int lengthOfRule)
{
    for(int i=0;i<lengthOfRule;i++)
    {
        if(a==rule[i])
        {
            return(i+1<lengthOfRule&&rule[i+1]==':');
        }
    }
    return 0;
}
int main()
{
    char rule[10240],token[1025][1025];
    int name;
    char ruleNeedValue[10240];
    memset(ruleNeedValue,' ',sizeof(ruleNeedValue));
    scanf("%s",rule);
    scanf("%s",&name);
    int tokenLength=0;
    while(scanf("%s",token[tokenLength++])!=EOF);
    for(int i=0;i<strlen(rule);i++)
    {
        if((i+1)<strlen(rule)&&rule[i+1]==':')
        {
            ruleNeedValue[i]='1';//寻找需要值的参数
        }
    }
    if(token[tokenLength][0]=='-')
    {
        for(int i=0;i<strlen(rule);i++)
        {
            if(rule[i]==token[tokenLength][1]&&ruleNeedValue[i]=='1')
            {
                printf("%s:option requires an argument -- '%s'",name,token[tokenLength][1]);
                return -1;
            }
        }
    }
    for(int i=0;i<tokenLength;i++)
    {
        if(token[i][0]=='-')
        {
            if(!IsValidOption(token[i][1],rule,strlen(rule)))
            {
                printf("%s:invalid option -- '%s'",name,token[i][1]);
                return -2;
            }
        }
    }
    printf("%s",name);
    for(int i=0;i<tokenLength;i++)
    {
        if(token[i][0]=='-')
        {
            for(int j=0;j<strlen(rule);j++)
            {
                if(token[i][1]==rule[j]&&ruleNeedValue[j]=='1')
                {
                    ruleNeedValue[j]=token[i+1];
                }
            }
        }
    }
    for(int i=0;i<tokenLength;i++)
    {
        if(token[i][0]=='-')
        {
            int temp=0;
            for(int j=0;j<strlen(rule);j++)
            {
                if(token[i][1]==rule[j]&&ruleNeedValue[j]=='1')
                {
                    printf("%s=%s\n",token[i],ruleNeedValue);
                    temp=1;
                }
            }
            if(temp)
            {
                printf("%s\n",token[i]);
            }
        }
    }
    return 0;
}