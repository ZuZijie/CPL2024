#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 1000

int V[MAX_N][MAX_M]; 
int ansPosi[MAX_N * MAX_M][2];
int ansN = 0;
int max_sum = INT_MIN; 

int calculateValue(int center_x, int center_y, int radius) {
    int value = 0;
    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            if ((dx * dx + dy * dy) <= radius * radius) {
                value += V[center_x + dx][center_y + dy];
            }
        }
    }
    return value;
}

int main() {
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &V[i][j]);
        }
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int value = calculateValue(i, j, d);

            if (value > max_sum) {
                max_sum = value;
                ansN = 1;
                ansPosi[0][0] = i;
                ansPosi[0][1] = j;
            } else if (value == max_sum) {
                ansPosi[ansN][0] = i;
                ansPosi[ansN][1] = j;
                ansN++;
            }
        }
    }

    printf("%d %d\n", max_sum, ansN);
    for (int i = 0; i < ansN; i++) {
        printf("%d %d\n", ansPosi[i][0], ansPosi[i][1]);
    }
    
    return 0;
}