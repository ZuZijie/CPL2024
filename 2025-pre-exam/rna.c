#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef struct rna
{
    char str;
    struct rna * nextRNA;
}rna;
int initRNA(char input[],rna *firstRNA){
    int len=strlen(input);
    rna * currentRNA=firstRNA;
    for(int i=1;i<len;i++){
        rna *newnode=malloc(sizeof(rna));
        currentRNA->nextRNA=newnode;
        newnode->str=input[i];
        currentRNA=newnode;
    }
    return 0;
}
int main()
{
    int n,m;
    char input[10000];
    scanf("%s",input);
    scanf("%d %d",&n,&m);
    char rule[100][100];
    char rule2[100][100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",rule[n]);
        scanf("%s",rule2[n]);
    }
    rna * firstRNA;
    firstRNA=malloc(sizeof(rna));
    firstRNA->str=input[0];
    initRNA(input,firstRNA);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // for(int k=0;k<)
        }
    }
}