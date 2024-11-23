#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
    char *s, *t;
    int *ans;
    int ansN = 0;
    ans = (int *)malloc(10000 * sizeof(int));
    s = (char *)malloc(100000 * sizeof(char));
    t = (char *)malloc(100000 * sizeof(char));
    scanf("%s %s", s, t);
    int sl = strlen(s);
    int tl = strlen(t);
    for (int i = 0; i <= sl - tl; i++) {
        int match = 1;
        for (int j = 0; j < tl; j++) {
            if (*(s+i+j)!= *(t+j)) {
                match = 0;
                break;
            }
        }
        if (match) {
            *(ans+ansN)=i;
            ansN++;
        }
    }

    for (int i = 0; i < ansN; i++) {
        printf("%d ", *(ans+i));
    }

    free(s);
    free(t);
    free(ans);

    return 0;
}
