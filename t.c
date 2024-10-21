#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define N 150

/*
 * 疑似要用到的新东西
 * strlen
 * isdigit
*/


int main (void)
{
    int amount;
    int length_string = 0;
    char rubbish;
    char string[150];
    char string1[16] = {0};
    scanf("%d", &amount);
    getchar();
    for(int i = 0, j = 0; i < amount; i++)
    {
        scanf("%s", &string1);
        getchar();
        length_string = strlen(string1);
        for(int k = 0; k < length_string; k++)
        {
            string[j + k] =  string1[k];
        }
        j += length_string;
        string[++j] = ' ';
    }
    printf("%s", string);
}