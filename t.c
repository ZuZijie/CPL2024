#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mystrcat(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 0; i < len2; i++) {
        *(s1+len1 + i) = *(s2+i);
    }
}

int main() {
    int T;
    scanf("%d", &T);



    for (int t = 0; t < T; t++) {
        char *s1 = (char *)malloc(2000 * sizeof(char));
        char *s2 = (char *)malloc(1000 * sizeof(char));
        memset(s1,' ',2000*sizeof(char));
        memset(s2,' ',sizeof(char)*1000);
        scanf("%s %s", s1, s2); 

        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int overlap = 0;


        for (int i = 0; i < len1; i++) {
            int match = 1; 
            for (int j = 0; j < len1 - i && j < len2; j++) {
                if (*(s1+i+j) != *(s2+j)) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                overlap = len1 - i;
                break;
            }
        }

        mystrcat(s1, s2 + overlap);
        printf("%s\n", s1);
        free(s1);
        free(s2);
    }



    return 0;
}
