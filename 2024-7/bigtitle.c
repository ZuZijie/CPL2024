#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *input;
    input = (char *)malloc(5000 * sizeof(char));
    fgets(input,5000,stdin);
    char *ptr = input;
    for(int i=0;*(ptr+i)!='\0';i++)
    {
        if(*(ptr+i)>='A' &&*(ptr+i)<='Z')
        *(ptr+i)=*(ptr+i)+32;
    }
    for (int i = 0; *(ptr + i) != '\0'; i++) 
    {
        if(i==0)
        {
            printf("%c", *(ptr + i)-32);
        } 
        else if (*(ptr + i - 1) == ' ' ) 
        {
            printf("%c", *(ptr + i) - 32); 
        } 
        else 
        {
            printf("%c", *(ptr + i)); 
        }
    }
    free(input);
    return 0;
}