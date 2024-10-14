#include "stdio.h"
int main()
{
    int n;
    char a[2000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &a[i]);    
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] == '?')
        {
            a[i] = a[n - 1 - i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%c", a[i]);
    }
    return 0;
}