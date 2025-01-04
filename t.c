#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define   delim "/"
int main(){
    char input[1000];
    scanf("%s",input);
    char *output=strtok(input,delim);
    int n;
    while(output!=NULL){
        printf("%s\n",output);
        // printf("%s\n",input);
        output=strtok(NULL,delim);
        
    }
    return 0;
}