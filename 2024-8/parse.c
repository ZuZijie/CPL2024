#include "stdio.h"
#include "stdlib.h"
int main()
{
    char input1[1000],name,input2[1000][1000];
    char relation[1000][2],relation2[1000][2];//r1用于存储第一次输入的从属关系，r2用于input2中的关系记录
    for(int i=0;i<1000;i++)relation2[i][1]='0';
    scanf("%s",input1);
    scanf("%s",name);
    int NumParameter=0;
    while(scanf("%s",input2[NumParameter++])!=EOF);
    int length1=strlen(input1);
    int numRelation=0,numRelation2=0;
    for(int i=0;i<length1-1;i++)
    {
        if(input1[i]==':')
        {
            relation[numRelation][0]=input1[i-1];
            relation[numRelation][1]=input1[i+1];
            numRelation++;
        }
        else
        {
            relation2[numRelation2][0]=input1[i];
            numRelation2++;
        }
    }
    if(input1[length1-1]=':')
    {
        relation[numRelation][0]=input1[length1-2];
        relation[numRelation][1]='0';
        numRelation++;
    }
    else
        {
            relation2[numRelation2][0]=input1[length1-1];
            numRelation2++;
        }
    for(int i=0;i<NumParameter;i++)
    {
        if(input2[i][0]=='-')
        {
            int didfind=0;
            for(int j=0;j<numRelation2;j++)
            {
                if(input2[i][1]==relation2[j][0])
                {
                    relation2[j][1]=input2[i][1];
                    didfind=1;
                }
            }
            if(!didfind)
            {
                printf("%s:invalid option -- '%s",name,input2[i][1]);
                return 0;
            }
        }
    }
    for(int i=0;i<numRelation2;i++)
    {
        if(relation2[i][1]==0)
        {
            printf("%s:option requires an argument -- '%s",name,relation2[i][0]);
            return 0;
        }
    }
    printf("%s\n",name);
    for(int i=0;i<numRelation2;i++)
    {
        for(int j=0;j<numRelation;j++)
        {
            if(relation[i][0]==)
        }
    }
}