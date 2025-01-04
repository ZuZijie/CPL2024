#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);  
}

int main() {
    int n;
    scanf("%d", &n);
    char *input = (char *)malloc(sizeof(char) * (n + 1));  

    getchar();  
    for (int i = 0; i < n; i++) {
        scanf("%c", &input[i]);
    }
    qsort(input, n, sizeof(char), cmp);
    for (int i = 0; i < n; i++) {
        printf("%c ", input[i]);
    }
    free(input);

    return 0;
}
