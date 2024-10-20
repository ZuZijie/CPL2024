#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main() {
    char res[10];
    unsigned int a=0;
    unsigned int b=(unsigned int)pow(2,32);
    unsigned int guess = 1;

    while (1) {
        guess=a+(b-a)/2;
        printf("%u\n", guess);
        fflush(stdout);
        scanf("%s", res);

        switch (res[0]) {
            case 'L': {
                a=guess+1;
                break;
            }
            case 'G': {
                b=guess-1;
                break;
            }
            case 'E': return 0;
            case 'O': return 0;
        }
    }
}