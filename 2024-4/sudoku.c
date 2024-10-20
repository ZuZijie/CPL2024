#include "stdio.h"

int main() {
    int answer = 1;
    int temp;
    int t[10] = {0}; 
    int in[9][9];

   
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &temp);
            if (temp < 1 || temp > 9) { 
                answer = 0;
            }
            in[i][j] = temp;
        }
    }

  
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) { 
            t[j] = 0;
        }
        for (int j = 0; j < 9; j++) {
            t[in[i][j]]++;
        }
        for (int j = 1; j <= 9; j++) { 
            if (t[j] > 1) answer = 0;
        }
    }

   
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            t[j] = 0;
        }
        for (int j = 0; j < 9; j++) {
            t[in[j][i]]++;
        }
        for (int j = 1; j <= 9; j++) { 
            if (t[j] > 1) answer = 0;
        }
    }

  
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            for (int k = 0; k < 10; k++) { 
                t[k] = 0;
            }
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    t[in[i + m][j + n]]++;
                }
            }
            for (int k = 1; k <= 9; k++) { 
                if (t[k] > 1) answer = 0;
            }
        }
    }


    printf("%s\n", answer ? "YES" : "NO");
    return 0;
}

