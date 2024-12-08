#include "stdio.h"
#include "string.h"
#include "stdlib.h"
    char input[1000000];
    char *tokens[100000];
int compar(const void *a, const void *b) 
{
    
    char *x = *(char **)a;
    char *y = *(char **)b;
    return strcmp(x, y);

}
int main()
{

    char splitChar[10];

    scanf("%s %s",input,splitChar);
    char *token=strtok(input,splitChar);
    int NumofToken=0;
    while(token!=NULL)
    {
        tokens[NumofToken]=malloc(strlen(token)+1);
        if(tokens[NumofToken]!=NULL)
        {
            strcpy(tokens[NumofToken],token);
            NumofToken++;
        }
        token=strtok(NULL,splitChar);
    }
    qsort(tokens,NumofToken,sizeof(char*),compar);
    for(int i=0;i<NumofToken;i++)
    {
        printf("%s\n",tokens[i]);
    }
}