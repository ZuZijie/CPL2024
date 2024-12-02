#include <stdio.h>
#include <string.h>


void interleaveString(char *s1, char *s2, int d_s1, int d_s2, int size, char *result) 
{
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int index_s1 = 0, index_s2 = 0, index_result = 0;
    int current_size = 0;

    while (index_s1 < len_s1 || index_s2 < len_s2) 
    {

        for (int i = 0; i < d_s1 && index_s1 < len_s1; i++) {
            result[index_result++] = s1[index_s1++];
            current_size++;
            if (current_size >= size) 
            {
                result[index_result] = '\0';
                return;
            }
        }
        for (int i = 0; i < d_s2 && index_s2 < len_s2; i++) 
        {
            result[index_result++] = s2[index_s2++];
            current_size++;
            if (current_size >= size) 
            {
                result[index_result] = '\0';
                return;
            }
        }
    }

    result[index_result] = '\0'; 
}

int main() 
{
    int T;
    scanf("%d", &T); 
    getchar(); 
    for(int t=0;t<T;t++)
    {
        char s1[1001], s2[1001];
        int d_s1, d_s2, size;
        char result[2001];
        char input[3000];
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%[^;];%[^;];%d;%d;%d", s1, s2, &d_s1, &d_s2, &size);
        interleaveString(s1, s2, d_s1, d_s2, size, result);
        result[size-1]='\0';
        printf("%s\n", result);
    }

    return 0;
}
